# SP_NEWDEVICEWIZARD_DATA structure

## Description

An SP_NEWDEVICEWIZARD_DATA structure is used by installers to extend the operation of the hardware installation wizard by adding custom pages. It is used with DIF_NEWDEVICEWIZARD_*XXX* installation requests.

## Members

### `ClassInstallHeader`

An install request header that contains the header size and the DIF code for the request. See [SP_CLASSINSTALL_HEADER](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_classinstall_header).

### `Flags`

Reserved. Must be zero.

### `DynamicPages`

An array of property sheet page handles. An installer can add the handles of custom wizard pages to this array.

### `NumDynamicPages`

The number of pages that are added to the **DynamicPages** array.

Because the array index is zero-based, this value is also the index to the next free entry in the array. For example, if there are 3 pages in the array, **DynamicPages[**3**]** is the next entry for an installer to use.

### `hwndWizardDlg`

The handle to the top-level window of the hardware installation wizard .

## Remarks

[SP_ADDPROPERTYPAGE_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_newdevicewizard_data) is an alias for this structure.

## See also

[DIF_NEWDEVICEWIZARD_FINISHINSTALL](https://learn.microsoft.com/windows-hardware/drivers/install/dif-newdevicewizard-finishinstall)

[DIF_NEWDEVICEWIZARD_POSTANALYZE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-newdevicewizard-postanalyze)

[DIF_NEWDEVICEWIZARD_PREANALYZE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-newdevicewizard-preanalyze)

[DIF_NEWDEVICEWIZARD_PRESELECT](https://learn.microsoft.com/windows-hardware/drivers/install/dif-newdevicewizard-preselect)

[DIF_NEWDEVICEWIZARD_SELECT](https://learn.microsoft.com/windows-hardware/drivers/install/dif-newdevicewizard-select)