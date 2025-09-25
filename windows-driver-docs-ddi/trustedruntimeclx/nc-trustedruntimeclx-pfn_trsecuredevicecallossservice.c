//Declaration

*PFN_TRSECUREDEVICECALLOSSSERVICE *PfnTrsecuredevicecallossservice;

// Definition

NTSTATUS *PfnTrsecuredevicecallossservice
(
    WDFOBJECT BindContext
    WDFDEVICE Device
    LPCGUID OSServiceGuid
    PTR_SERVICE_REQUEST CallData
    ULONG_PTR *BytesWritten
)
{...}