## Description

Converts Direct2D primitives in the passed-in command list into a fixed page representation for use by the print subsystem.

## Parameters

### `commandList` [in]

Type: **[ID2D1CommandList](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1commandlist)***

The command list that contains the rendering operations.

### `pageSize`

Type: **[D2D_SIZE_F](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d_size_f)**

The size of the page to add, in DIPs (1 inch == 96 DIP). If the print driver doesn't respond to this parameter, then you can use *pagePrintTicketStream* instead.

### `pagePrintTicketStream` [in, optional]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

The print ticket stream. You can use this to modify properties of the current page; for example, paper size or orientation.

### `tag1` [out, optional]

Type: **[D2D1_TAG](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-tag)***

Contains the first label for subsequent drawing operations. This parameter is passed uninitialized. If NULL is specified, no value is retrieved for this parameter.

### `tag2` [out, optional]

Type: **[D2D1_TAG](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-tag)***

Contains the second label for subsequent drawing operations. This parameter is passed uninitialized. If NULL is specified, no value is retrieved for this parameter.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid parameter was passed to the returning function. |
| D2DERR_PRINT_JOB_CLOSED | The print job is already finished. |

## See also

[ID2D1PrintControl](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1printcontrol)