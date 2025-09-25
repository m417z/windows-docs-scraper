# IUnknown_Set function

## Description

Changes the value of a Component Object Model (COM) interface pointer and releases the previous interface.

## Parameters

### `ppunk` [in, out]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)****

The address of a COM interface pointer to receive the pointer assigned to *punk*. If the previous value of the pointer is non-**NULL**, the function releases that interface by calling its IUnkown::Release method.

### `punk` [in, optional]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

The interface pointer to be copied to *ppunk*. If the value is non-**NULL**, the function increments the interface's reference count.

## Remarks

This function mimics the behavior of a smart pointer. Conceptually, the function does the following:

* Releases the original interface, if *ppunk* is non-**NULL**
* Assigns *punk* to *ppunk*
* Calls IUnknown::AddRef on the interface pointed to by *punk*, if *punk* is non-**NULL**.

#### Examples

```cpp

void sample()
{
  IUnknown *punk = NULL;
  IStream* pstm = NULL;

  if (SUCCEEDED(CreateStreamOnHGlobal(NULL, TRUE, &pstm)) {
    // since punk == NULL, this merely copies the value and AddRef()s it
    IUnknown_Set(&punk, pstm);
    pstm->Release();

    if (SUCCEEDED(CreateStreamOnHGlobal(NULL, TRUE, &pstm)) {
      // this call will release the old value of punk before copying the
      // new value and AddRef()ing it
      IUnknown_Set(&punk, pstm);
      pstm->Release();
    }
  }

  // This call will release whatever punk points to, if anything.
  IUnknown_AtomcRelease((void**)&punk);

  // at this point, punk == NULL
}
```