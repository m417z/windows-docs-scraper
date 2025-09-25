# IClosable::IClosable

## Description

Performs application-defined tasks associated with freeing, releasing, or resetting allocated resources.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Calling the **Close** method more than once has no effect and returns **S_OK**.

For info on implementing the **Close** method, see the Remarks at [IClosable](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nn-windows-foundation-iclosable).

## See also

[IClosable](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nn-windows-foundation-iclosable)