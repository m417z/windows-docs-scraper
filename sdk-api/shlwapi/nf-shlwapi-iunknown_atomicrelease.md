# IUnknown_AtomicRelease function

## Description

Releases a Component Object Model (COM) pointer and sets it to **NULL**.

## Parameters

### `ppunk` [in, out, optional]

Type: **void****

The address of a pointer to a COM interface.

## Remarks

If *ppunk* points to a **NULL** pointer, no operation is performed. Otherwise, *ppunk* is assumed to be the address of a COM interface pointer, derived from [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown). The function calls the interface's [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method then sets the interface pointer to **NULL**.

#### Examples

The following example uses **IUnknown_AtomicRelease** to release the stream, if it exists. If not, it does nothing.

```cpp
void sample()
{
    IStream *pstm = NULL;
    CreateStreamOnHGlobal(NULL, TRUE, &pstm);

    IUnknown_AtomicRelease((void**)&pstm);

    // At this point, pstm is NULL
}
```