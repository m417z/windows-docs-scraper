# MBB_DEVICE_MBIM_PARAMETERS_INIT function

## Description

The **MBB_DEVICE_MBIM_PARAMETERS_INIT** method initializes a [**MBB_DEVICE_MBIM_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/ns-mbbcx-_mbb_device_mbim_parameters) structure.

## Parameters

### `MbimParameters`

A pointer to the client driver-allocated [**MBB_DEVICE_MBIM_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/ns-mbbcx-_mbb_device_mbim_parameters) structure to be initialized.

### `Version`

An [**MBB_MBIM_VERSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/ne-mbbcx-_mbb_mbim_version) value that defines the version of the MBIM specification that the client driver supports. The value of this field must be **MBB_MBIM_VERSION1_0_ERRATA**.

### `MaximumFragmentSize`

The maximum size, in bytes, of MBIM control messages that the client driver can support.

### `ExtendedVersion`

An [**MBB_MBIM_EXTENDED_VERSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/ne-mbbcx-_mbb_mbim_extended_version) value that defines the version of the lowest extended MBIM specification that the client driver supports. If a device sets **MbbMbimExtendedVersion2Dot0**, it means the device can only support **MbbMbimExtendedVersion2Dot0** or higher. So if a device with intention to work with older hosts should set **MbbMbimExtendedVersion1Dot0**

## Remarks

The client driver typically calls this method from its [*EVT_WDF_DEVICE_PREPARE_HARDWARE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) event callback function in preparation for calling [**MbbDeviceSetMbimParameters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nf-mbbcx-mbbdevicesetmbimparameters).

## See also

[Mobile Broadband (MBB) WDF class extension (MBBCx)](https://learn.microsoft.com/windows-hardware/drivers/netcx/mobile-broadband-mbb-wdf-class-extension-mbbcx)