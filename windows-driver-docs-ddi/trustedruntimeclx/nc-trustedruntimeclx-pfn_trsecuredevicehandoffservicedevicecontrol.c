//Declaration

PFN_TRSECUREDEVICEHANDOFFSERVICEDEVICECONTROL PfnTrsecuredevicehandoffservicedevicecontrol;

// Definition

WDFAPI PfnTrsecuredevicehandoffservicedevicecontrol
(
    WDFOBJECT BindContextObject
    PWDFDEVICE_INIT DeviceInit
    LPGUID ServiceGuid
    PTR_SECURE_SERVICE_CALLBACKS Callbacks
    WDFDEVICE *ServiceDevice
)
{...}