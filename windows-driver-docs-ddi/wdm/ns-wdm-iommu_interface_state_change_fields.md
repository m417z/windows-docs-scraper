## Description

**IOMMU_INTERFACE_STATE_CHANGE_FIELDS** represents the fields of an [**IOMMU_INTERFACE_STATE_CHANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_interface_state_change), indicating the caller's wish to be notified of a change of a specific state field(s) or indicating to callback owners which states have changed.

When a caller attempts to register an [**IOMMU_INTERFACE_STATE_CHANGE_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_interface_state_change_callback) through [**IOMMU_REGISTER_INTERFACE_STATE_CHANGE_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_register_interface_state_change_callback), these fields indicate the state(s) that the caller wants to be notified about.

When a registered [**IOMMU_INTERFACE_STATE_CHANGE_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_interface_state_change_callback) is invoked, the callback owner receives an [**IOMMU_INTERFACE_STATE_CHANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_interface_state_change); these fields indicate which states have changed.

## Members

### `DUMMYSTRUCTNAME`

A structure containing various states of an IOMMU interface.

### `DUMMYSTRUCTNAME.AvailableDomainTypes`

When set to 1, this indicates that the caller wants to be notified (via the provided callback) when the available domain types change or this indicates to callback owners that the available domain types have changed.

### `DUMMYSTRUCTNAME.Reserved`

Reserved for future fields. Currently unused.

### `AsULONG`

The consolidated values of the fields in **DUMMYSTRUCTNAME**.

## Remarks

## See also

[**IOMMU_INTERFACE_STATE_CHANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_interface_state_change)

[**IOMMU_INTERFACE_STATE_CHANGE_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_interface_state_change_callback)

[**IOMMU_REGISTER_INTERFACE_STATE_CHANGE_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_register_interface_state_change_callback)