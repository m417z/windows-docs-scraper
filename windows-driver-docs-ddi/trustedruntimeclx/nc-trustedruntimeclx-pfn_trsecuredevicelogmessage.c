//Declaration

*PFN_TRSECUREDEVICELOGMESSAGE *PfnTrsecuredevicelogmessage;

// Definition

NTSTATUS *PfnTrsecuredevicelogmessage
(
    WDFOBJECT BindContext
    WDFDEVICE Device
    ULONG Severity
    PCSTR Message
    va_list Arguments
)
{...}