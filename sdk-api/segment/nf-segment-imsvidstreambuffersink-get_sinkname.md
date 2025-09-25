# IMSVidStreamBufferSink::get_SinkName

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_SinkName** method retrieves the name of the stub file that points to the backing files.

## Parameters

### `pName` [out]

Pointer to a variable that receives the file name.

## Return value

The method returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_POINTER** | NULL pointer argument. |
| **S_OK** | The method succeeded. |

## Remarks

The caller must release the returned string, using the **SysFreeString** function.

## See also

[Buffering in the Stream Buffer Engine](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/buffering-in-the-stream-buffer-engine)

[IMSVidStreamBufferSink Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidstreambuffersink)