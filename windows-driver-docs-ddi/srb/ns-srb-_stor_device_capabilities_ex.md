# STOR_DEVICE_CAPABILITIES_EX structure (srb.h)

## Description

The **STOR_DEVICE_CAPABILITIES_EX** structure reports device capabilities to the SCSI port driver in response to a capabilities query in a SCSI request block (SRB) with a function of SRB_FUNCTION_PNP. **STOR_DEVICE_CAPABILITIES** is a subset of the [**DEVICE_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_capabilities) structure containing the members relevant to storage devices.

## Members

### `Version`

Specifies the version of the structure. Set to STOR_DEVICE_CAPABILITIES_EX_VERSION_1 by Storport.

### `Size`

Specifies the size of the structure. Set to **sizeof**(STOR_DEVICE_CAPABILITIES_EX) by Storport.

### `DeviceD1`

Specifies whether the device hardware supports the D1 power state. Miniport drivers set this bit to 0.

### `DeviceD2`

Specifies whether the device hardware supports the D2 power state. Miniport drivers set this bit to 0.

### `LockSupported`

Specifies whether the device supports physical-device locking that prevents device ejection. This member pertains to ejecting a LUN or a unit device.

### `EjectSupported`

Specifies whether the device supports software-controlled device ejection while the system is in the **PowerSystemWorking** state. This member pertains to ejecting a LUN or unit device.

### `Removable`

Specifies whether the device can be dynamically removed from its immediate parent. If **Removable** is set to TRUE:

* The device does not belong to the same physical object as its parent.
* The device is displayed in the Unplug or Eject Hardware program, unless **SurpriseRemovalOK** is also set to TRUE.

### `DockDevice`

Specifies whether the device is a docking peripheral.

### `UniqueID`

Specifies whether the device's instance ID is unique system-wide. This bit is clear if the instance ID is unique only within the scope of the bus.

### `SilentInstall`

Specifies whether **Device Manager** should suppress all installation dialog boxes; except required dialog boxes such as "no compatible drivers found."

### `RawDeviceOK`

Specifies whether the driver for the underlying bus can drive the device if there is no function driver (for example, SCSI devices in pass-through mode). This mode of operation is called raw mode.

### `SurpriseRemovalOK`

Specifies whether the miniport driver for the device can handle the case where the device is removed before SCSI port can send SRB_FUNCTION_PNP with **StorRemoveDevice** as the **PnPAction** in the [**SCSI_PNP_REQUEST_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_pnp_request_block) structure. If **SurpriseRemovalOK** is set to **TRUE**, the device can be safely removed from its immediate parent regardless of the state that its driver is in.

### `NoDisplayInUI`

Do not display the device in the user interface. If this bit is set, the device is never displayed in the user interface, even if the device is present but fails to start. Miniport drivers do not set this bit.

### `DefaultWriteCacheEnabled`

The storage device's write cache is enabled by default at initialization.

### `Reserved0`

Reserved bits.

### `Address`

LUN address of the storage unit device.

### `UINumber`

Specifies a number associated with the device that can be displayed in the user interface.

This number might be an ID value chosen to make locating the physical device easier for the user. When the **UINumber** is unknown, the miniport driver can set this member to its default value of 0xFFFFFFFF.

### `Reserved1[2]`

Reserved bits.

## Remarks

When a miniport driver receives an SRB in its [**HwStorStartIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nc-srb-phw_startio) routine where the SRB function is SRB_FUNCTION_PNP, the SRB is formatted as a [**SCSI_PNP_REQUEST_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_pnp_request_block) structure. If the **PnPAction** member of the SRB is **StorQueryCapabilities**, the miniport can return a **STOR_DEVICE_CAPABILITIES_EX** structure in the **DataBuffer** member of the SRB.

The eject, removal, and install characteristics for the device are set in the **STOR_DEVICE_CAPABILITIES_EX** structure. To support the use of this structure, the miniport must set the STOR_FEATURE_FULL_PNP_DEVICE_CAPABILITIES flag in the **FeatureSupport** flags member in [**HW_INITIALIZATION_DATA (SCSI)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_hw_initialization_data) before calling [**ScsiPortInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportinitialize).

## See also

[**DEVICE_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_capabilities)

[**HW_INITIALIZATION_DATA (SCSI)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_hw_initialization_data)

[**SCSI_PNP_REQUEST_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_pnp_request_block)

[**ScsiPortInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportinitialize)