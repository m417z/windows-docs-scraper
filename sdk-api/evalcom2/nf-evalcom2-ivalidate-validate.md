# IValidate::Validate

## Description

The **Validate** method performs validation of the installation package or merge module using the specified internal consistency evaluator file.

## Parameters

### `wzICEs` [in, optional]

Optional parameter that specifies which [Internal Consistency Evaluators (ICE)](https://learn.microsoft.com/windows/desktop/Msi/internal-consistency-evaluators-ices) should run. You can specify the ICEs in a delimited list or in a custom table.

When providing a delimited list of ICEs to be run, separate the ICEs in the list by colons (:), for example, "ICE01:ICE03:ICE08".

When providing the name of a custom sequence table, the ICEs to be run can be entered in the custom table.

If the value of *szICEs* is **NULL**, all ICEs in the _ICESequence table are run. The _ICESequence table is the default table provided with orca.msi and msival2.msi.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_PENDING** | The method failed. |
| **E_FAIL** | The method failed. |

## See also

[IValidate](https://learn.microsoft.com/windows/desktop/api/evalcom2/nn-evalcom2-ivalidate)

[Using Evalcom2](https://learn.microsoft.com/windows/desktop/Msi/using-evalcom2)

[Validation Callback Functions](https://learn.microsoft.com/windows/desktop/Msi/validation-callback-functions)