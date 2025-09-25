# _MSiSCSI_AdapterEvent structure

## Description

The MSiSCSI_AdapterEvent structure contains information that is reported whenever an adapter event occurs.

## Members

### `UniqueAdapterId`

A 64-bit integer that uniquely identifies an HBA initiator and a loaded instance of a storage miniport driver that manages the HBA. The initiator should use the address of the adapter extension or another address that the device driver owns to construct this identifier (ID). The initiator reports this value in the **UniqueAdapterId** member of the [MSiSCSI_HBAInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsimgt/ns-iscsimgt-_msiscsi_hbainformation) structure.

### `EventCode`

An [ISCSI_ADAPTER_EVENT_CODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ne-iscsiop-iscsi_adapter_event_code) enumeration value that indicates the type of adapter event that occurred.

## Remarks

The WMI tool suite automatically generates a declaration of the MSiSCSI_AdapterEvent structure when it compiles the [MSiSCSI_AdapterEvent WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-adapterevent-wmi-class) in *Operations.mof*. You must implement this method if the adapter supports discovery.

## See also

[ISCSI_ADAPTER_EVENT_CODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ne-iscsiop-iscsi_adapter_event_code)

[MSiSCSI_AdapterEvent WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-adapterevent-wmi-class)

[MSiSCSI_HBAInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsimgt/ns-iscsimgt-_msiscsi_hbainformation)