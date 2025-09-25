# IMFASFSplitter::GetSelectedStreams

## Description

Gets a list of currently selected streams.

## Parameters

### `pwStreamNumbers` [out]

The address of an array of **WORDs**. This array receives the stream numbers of the selected streams.
This parameter can be **NULL**.

### `pwNumStreams` [in, out]

On input, points to a variable that contains the number of elements in the *pwStreamNumbers* array. Set the variable to zero if *pwStreamNumbers* is **NULL**.

On output, receives the number of elements that were copied into *pwStreamNumbers*. Each element is the identifier of a selected stream.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Invalid argument. |
| **MF_E_BUFFERTOOSMALL** | The *pwStreamNumbers* array is smaller than the number of selected streams. See Remarks. |

## Remarks

To get the number of selected streams, set *pwStreamNumbers* to **NULL**. The method will return **MF_E_BUFFERTOSMALL** but will also set the value of `*pwNumStreams` equal to the number of selected streams. Then allocate an array of that size and call the method again, passing the array in the *pwStreamNumbers* parameter.

The following code shows these steps:

```cpp
HRESULT DisplaySelectedStreams(IMFASFSplitter *pSplitter)
{
    WORD count = 0;
    HRESULT hr = pSplitter->GetSelectedStreams(NULL, &count);
    if (hr == MF_E_BUFFERTOOSMALL)
    {
        WORD *pStreamIds = new (std::nothrow) WORD[count];
        if (pStreamIds)
        {
            hr = pSplitter->GetSelectedStreams(pStreamIds, &count);
            if (SUCCEEDED(hr))
            {
                for (WORD i = 0; i < count; i++)
                {
                    printf("Selected stream ID: %d\n", pStreamIds[i]);
                }
            }
            delete [] pStreamIds;
        }
        else
        {
            hr = E_OUTOFMEMORY;
        }
    }
    return hr;
}

```

Alternatively, you can allocate an array that is equal to the total number of streams and pass that to *pwStreamNumbers*.

Before calling this method, initialize `*pwNumStreams` to the number of elements in *pwStreamNumbers*. If *pwStreamNumbers* is **NULL**, set `*pwNumStreams` to zero.

By default, no streams are selected by the splitter. Select streams by calling the [IMFASFSplitter::SelectStreams](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfsplitter-selectstreams) method.

## See also

[ASF Splitter](https://learn.microsoft.com/windows/desktop/medfound/asf-splitter)

[IMFASFSplitter](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfsplitter)