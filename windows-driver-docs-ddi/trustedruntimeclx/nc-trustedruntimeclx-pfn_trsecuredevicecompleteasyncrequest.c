//Declaration

*PFN_TRSECUREDEVICECOMPLETEASYNCREQUEST *PfnTrsecuredevicecompleteasyncrequest;

// Definition

NTSTATUS *PfnTrsecuredevicecompleteasyncrequest
(
    WDFOBJECT BindContext
    PVOID RequestHandle
    NTSTATUS Result
    ULONG_PTR BytesWritten
)
{...}