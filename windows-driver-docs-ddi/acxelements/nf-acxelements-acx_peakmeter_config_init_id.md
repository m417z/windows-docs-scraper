## Description

At this time, the **ACX_PEAKMETER_CONFIG_INIT_ID** function can only take AcxElementIdDefault as input for the element ID, which is the same as using ACX_PEAKMETER_CONFIG_INIT. Because of this, [ACX_PEAKMETER_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/nf-acxelements-acx_peakmeter_config_init) is recommended.

## Parameters

### `Config`

An [ACX_PEAKMETER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_peakmeter_config) structure.

### `Id`

Set only to AcxElementIdDefault that is defined in the AcxElements header.

## Remarks

As the ACX_PEAKMETER_CONFIG_INIT_ID provides the same functionality as [ACX_PEAKMETER_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/nf-acxelements-acx_peakmeter_config_init), the use of ACX_PEAKMETER_CONFIG_INIT is recommended.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)