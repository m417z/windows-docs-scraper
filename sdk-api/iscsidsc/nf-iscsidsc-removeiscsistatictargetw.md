# RemoveIScsiStaticTargetW function

## Description

The **RemoveIscsiStaticTarget** function removes a target from the list of static targets made available to the machine.

## Parameters

### `TargetName` [in]

The name of the iSCSI target to remove from the static list.

## Return value

Returns ERROR_SUCCESS if the operation succeeds. Otherwise, it returns the appropriate Win32 or iSCSI error code.

## See also

[AddIscsiStaticTarget](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-addiscsistatictargeta)

## Remarks

> [!NOTE]
> The iscsidsc.h header defines RemoveIScsiStaticTarget as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).