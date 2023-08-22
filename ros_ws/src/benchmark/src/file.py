#!/usr/bin/env python
import rospy
import os
import csv
import sys

class FILE:
    def __init__(self, N, M, fre, payload):
        self.N = N
        self.M = M
        self.fre = fre
        self.payload = payload
        self.file_dir = "/root/ros_ws/src/benchmark/tmp/"
        self.combine_dir = "/root/ros_ws/src/benchmark/output/"
        
        self.file_names = None
        
    def get_file_names(self):
        self.file_names = [file for file in os.listdir(self.file_dir) if os.path.isfile(os.path.join(self.file_dir, file))]
        # print(self.file_names)

    def combine_files(self):
        # Initialize an empty list to hold the combined rows
        combined_rows = []

        # Read data from each CSV file and add its rows to the combined_rows list
        for f in self.file_names:
            file_name = self.file_dir + f
            with open(file_name, 'r') as csv_file:
                reader = csv.reader(csv_file)
                for row in reader:
                    combined_rows.append(row)

        # Write the combined rows to a new CSV file
        output_path = self.combine_dir + "N=" + self.N + "_M=" + self.M + "_fre=" + self.fre + "_payload=" + self.payload + ".csv"
        with open(output_path, 'w', newline='') as combined_file:
            writer = csv.writer(combined_file)
            writer.writerows(combined_rows)
    
    def delete_file(self):
        for file_name in self.file_names:
            file_path = os.path.join(self.file_dir, file_name)
            if os.path.isfile(file_path):
                os.remove(file_path)
                print(f"Deleted: {file_path}")
            else:
                print(f"Skipped (not a file): {file_path}")
        


if __name__ == '__main__':
    if(len(sys.argv)!=5):
        print("<N>, <M>, <freq>, <payload>")
    
    else:
        N, M, fre, payload = sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4]
        f = FILE(N, M, fre, payload)
        
        f.get_file_names()
        f.combine_files()
        f.delete_file()