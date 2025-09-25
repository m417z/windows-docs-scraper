# ID2D1CommandList::Stream

## Description

Streams the contents of the command list to the specified command sink.

## Parameters

### `sink` [in]

Type: **[ID2D1CommandSink](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1commandsink)***

The sink into which the command list will be streamed.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If it fails, it returns an **HRESULT** error code.

The return value indicates any failures the command sink implementation returns through its [EndDraw](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1commandsink-enddraw) method.

## Remarks

The command sink can be implemented by any caller of the API.

If the caller makes any design-time failure calls while a command list is selected as a target, the command list is placed in an error state. The stream call fails without making any calls to the passed in sink.

Sample use:

```cpp
Class MyCommandSink : public ID2D1CommandSink
{
public:
    // All of the ID2D1CommandSink methods implemented here.
};

HRESULT
StreamToMyCommandSink(
    __in ID2D1CommandList *pCommandList
    )
{
    HRESULT hr = S_OK;

    MyCommandSink *pCommandSink = new MyCommandSink();
    hr = pCommandSink ? S_OK : E_OUTOFMEMORY;

    if (SUCCEEDED(hr))
    {
        // Receive the contents of the command sink streamed to the sink.
        hr = pCommandList->Stream(pCommandSink);
    }

    SafeRelease(&pCommandSink);

    return hr;

}
```

## See also

[ID2D1CommandList](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1commandlist)