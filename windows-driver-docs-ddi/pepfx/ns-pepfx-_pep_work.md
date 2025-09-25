# _PEP_WORK structure (pepfx.h)

## Description

The **PEP_WORK** structure indicates whether the PEP has a work request to submit to the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/kernel/overview-of-the-power-management-framework) (PoFx).

## Members

### `WorkInformation` [out]

A pointer to a PEP-allocated [PEP_WORK_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_work_information) structure that describes the work that the PEP is requesting. If **NeedWork** is TRUE, **WorkInformation** must point to a valid **PEP_WORK_INFORMATION** structure. If **NeedWork** is FALSE, **WorkInformation** must be NULL.

### `NeedWork` [out]

Whether the PEP has a work request to submit. Set this member to TRUE if the PEP has a work request, or to FALSE if the PEP has no work to request.

## Remarks

This structure is used by the [PEP_DPM_WORK](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-peps-for-acpi-services) notification. Both members of the structure contain values that the PEP writes to the structure in response to this notification.

## See also

[PEP_DPM_WORK](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-peps-for-acpi-services)

[PEP_WORK_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_work_information)