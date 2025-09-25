# IPropertyStore::Commit

## Description

After a change has been made, this method saves the changes.

## Return value

The `IPropertyStore::Commit` method returns any one of the following:

| Return code | Description |
| --- | --- |
| **S_OK** | All of the property changes were successfully written to the stream or path. This includes the case where no changes were pending when the method was called and nothing was written. |
| **STG_E_ACCESSDENIED** | The stream or file is read-only; the method was not able to set the value. |
| **E_FAIL** | Some or all of the changes could not be written to the file. Another, more explanatory error can be used in place of E_FAIL. |

## Remarks

Before the `Commit` method returns, it releases the file stream or path that was initialized to be used by the method. Therefore, no **IPropertyStore** methods succeed after `Commit` returns. At that point, they return E_FAIL.

Property handlers must ensure that property changes result in a valid destination file, even if the `Commit` process terminates abnormally, or encounters any errors.

## See also

[IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore)