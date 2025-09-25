//Declaration

*PFN_TRSECUREDEVICEQUERYOSSERVICE *PfnTrsecuredevicequeryosservice;

// Definition

NTSTATUS *PfnTrsecuredevicequeryosservice
(
    WDFOBJECT BindContext
    WDFDEVICE Device
    LPCGUID OSServiceGuid
    PTR_SERVICE_INFORMATION Information
)
{...}