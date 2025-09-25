//Declaration

PFN_TRSECUREDEVICEHANDOFFMASTERDEVICECONTROL PfnTrsecuredevicehandoffmasterdevicecontrol;

// Definition

WDFAPI PfnTrsecuredevicehandoffmasterdevicecontrol
(
    WDFOBJECT BindContextObject
    PWDFDEVICE_INIT DeviceInit
    PTR_SECURE_DEVICE_CALLBACKS Callbacks
    WDFDEVICE *MasterDevice
)
{...}