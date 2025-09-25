# STOR_DEVICE_CAPABILITIES structure (minitape.h)

## Description

The **STOR_DEVICE_CAPABILITIES** structure reports device capabilities to the Storport driver in response to a capabilities query in a SCSI request block (SRB) with a function of SRB_FUNCTION_PNP. **STOR_DEVICE_CAPABILITIES** is a subset of the [**DEVICE_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_capabilities) structure containing the members relevant to storage devices.

## Members

### `Version`

Specifies the version of the structure. Storport sets this field to STOR_DEVICE_CAPABILITIES_EX_VERSION_1.

### `DeviceD1`

Specifies whether the device hardware supports the D1 power state. Miniport drivers set this bit to 0.

### `DeviceD2`

Specifies whether the device hardware supports the D2 power state. Miniport drivers set this bit to 0.

### `LockSupported`

Specifies whether the device supports physical-device locking that prevents device ejection. This member pertains to ejecting a LUN or a unit device.

### `EjectSupported`

Specifies whether the device supports software-controlled device ejection while the system is in the **PowerSystemWorking** state. This member pertains to ejecting a LUN or unit device.

### `Removable`

Specifies whether the device can be dynamically removed from its immediate parent. If **Removable** is set to **TRUE**, the device does not belong to the same physical object as its parent.

If **Removable** is set to **TRUE**, the device is displayed in the Unplug or Eject Hardware program, unless **SurpriseRemovalOK** is also set to **TRUE**.

### `DockDevice`

Specifies whether the device is a docking peripheral.

### `UniqueID`

Specifies whether the device's instance ID is unique system-wide. This bit is clear if the instance ID is unique only within the scope of the bus.

### `SilentInstall`

Specifies whether **Device Manager** should suppress all installation dialog boxes; except required dialog boxes such as "no compatible drivers found."

### `SurpriseRemovalOK`

Specifies whether the miniport driver for the device can handle the case where the device is removed before Storport can send SRB_FUNCTION_PNP with **StorRemoveDevice** as the **PnPAction** in the [**SCSI_PNP_REQUEST_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_scsi_pnp_request_block) structure. If **SurpriseRemovalOK** is set to **TRUE**, the device can be safely removed from its immediate parent regardless of the state that its driver is in.

### `NoDisplayInUI`

Do not display the device in the user interface. If this bit is set, the device is never displayed in the user interface, even if the device is present but fails to start. Miniport drivers do not set this bit.

## Remarks

When a miniport driver receives an SRB in its [**HwStorStartIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_startio) routine where the SRB function is SRB_FUNCTION_PNP, the SRB is formatted as a [**SCSI_PNP_REQUEST_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_scsi_pnp_request_block) structure. If the **PnPAction** member of the SRB is **StorQueryCapabilities**, the miniport can return a **STOR_DEVICE_CAPABILITIES** structure in the **DataBuffer** member of the SRB.

Storport sends this structure to the miniport with all members initialized to 0. On return, only the **Removable** field is used from this structure.

Starting with Windows 8, miniports should use the [**STOR_DEVICE_CAPABILITIES_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_device_capabilities_ex) structure to indicate support for additional capabilities.

## See also

[**DEVICE_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_capabilities)

[**SCSI_PNP_REQUEST_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_scsi_pnp_request_block)

[**STOR_DEVICE_CAPABILITIES_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_device_capabilities_ex)