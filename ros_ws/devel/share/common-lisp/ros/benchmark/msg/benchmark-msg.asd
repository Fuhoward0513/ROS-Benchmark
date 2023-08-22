
(cl:in-package :asdf)

(defsystem "benchmark-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "payload" :depends-on ("_package_payload"))
    (:file "_package_payload" :depends-on ("_package"))
  ))