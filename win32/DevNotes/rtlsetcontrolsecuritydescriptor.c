NTSTATUS NTAPI RtlSetControlSecurityDescriptor (
     IN PSECURITY_DESCRIPTOR pSecurityDescriptor,
     IN SECURITY_DESCRIPTOR_CONTROL ControlBitsOfInterest,
     IN SECURITY_DESCRIPTOR_CONTROL ControlBitsToSet
     );