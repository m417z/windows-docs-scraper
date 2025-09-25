# IPrintCoreHelperUni2::GetNamedCommand

## Description

The **GetNamedCommand** method returns the specified command.

## Parameters

### `pDevmode` [in]

A pointer to a DEVMODE structure.

### `cbSize` [in]

The number of bytes in *pDevmode*, not the number of bytes written.

### `pszCommandName` [in]

The command name. This parameter accepts standard command names from the GPD, except for those that require an *Order attribute. Those six sections of ordered command sequences are accessible via the following special command names:

* L"SectionJobSetup"
* L"SectionDocSetup"
* L"SectionPageSetup"
* L"SectionPageFinish"
* L"SectionDocFinish"
* L"SectionJobFinish"

### `ppCommandBytes` [out]

The output buffer. This buffer does not need to be freed by the caller.

### `pcbCommandSize` [out]

The size of the output buffer.

## Return value

This method returns an **HRESULT** value.

## Remarks

The **GetNamedCommand** method will not return commands containing references to Standard Variables.

## See also

[IPrintCoreHelperUni2](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcorehelperuni2)