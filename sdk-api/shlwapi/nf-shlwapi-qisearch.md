# QISearch function

## Description

A table-driven implementation of the [IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method.

## Parameters

### `that` [in]

Type: **void***

A pointer to the base of a COM object.

### `pqit` [in]

Type: **LPCQITAB**

An array of [QITAB](https://learn.microsoft.com/windows/desktop/api/shlwapi/ns-shlwapi-qitab) structures. The last structure in the array must have its **piid** member set to **NULL** and its **dwOffset** member set to 0.

### `riid` [in]

Type: **REFIID**

A reference to the IID of the interface to retrieve through *ppv*.

### `ppv` [out]

Type: **void****

When this method returns successfully, contains the interface pointer requested in *riid*.

## Return value

Type: **HRESULT**

Returns S_OK if the requested interface was found in the table or if the requested interface was IUnknown. Returns E_NOINTERFACE if the requested interface was not found.

## Remarks

**Note** Prior to Windows Vista, **QISearch** was not exported by name or declared in a public header file. To use it in those cases, you must use [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) and request ordinal 219 from Shlwapi.dll to obtain a function pointer. Under Windows Vista, **QISearch** is included in Shlwapi.h and this is not necessary.

If the requested interface is IUnknown, then **QISearch** uses the first entry of the specified array of [QITAB](https://learn.microsoft.com/windows/desktop/api/shlwapi/ns-shlwapi-qitab) structures. Otherwise, **QISearch** searches the table until it either finds a matching IID or reaches the end of the table. If a matching IID is found, the function advances the associated interface pointer by the number of bytes specified by the **dwOffset** member of the interface's **QITAB** structure and reinterpreted as a COM pointer. That pointer is assigned to the **QISearch** function's *ppv* parameter. The method also calls IUnknown::AddRef to increment the interface's reference count.

If **QISearch** reaches the end of the table without finding the interface, it returns E_NOINTERFACE and sets *ppv* to **NULL**.

It is important to include all applicable interfaces in the table. For example, if the object implements a derived interface, you should also include the base interface in the table.

We recommend that you use the [IID_PPV_ARGS](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-iid_ppv_args) macro, defined in Objbase.h, to package the *riid* and *ppv* parameters. This macro provides the correct IID based on the interface pointed to by the value in *ppv*, which eliminates the possibility of a coding error in *riid* that could lead to unexpected results.

**Note** Active Template Library (ATL) provides a significantly better version of a table-driven implementation of QueryInterface.

#### Examples

The following example illustrates how to use **QISearch** to implement QueryInterface. It uses the offsetofclass macro from ATL to compute the offset from the base of the CSample object to a specified interface.

This object supports two interfaces aside from IUnknown, so there are two non-**NULL** entries in the [QITAB](https://learn.microsoft.com/windows/desktop/api/shlwapi/ns-shlwapi-qitab) table. The entry for each interface specifies a pointer to the associated IID (IID_IPersist or IID_IPersistFolder) and the offset of the interface pointer relative to the class's base pointer. The sample uses the **offsetofclass** macro from ATL to determine that offset.

**Note** Forgetting to include all base classes, including indirect ones, is a common error. Notice that there is an entry for the [IPersist](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersist) interface. This interface is an indirect base class for CSample, inherited through [IPersistFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ipersistfolder).

```cpp

class CSample : public IPersistFolder
{
  public:
    CSample() { /* other construction goes here */ }

    STDMETHODIMP QueryInterface(REFIID riid, void **ppv);
    STDMETHODIMP_(ULONG) AddRef();
    STDMETHODIMP_(ULONG) Release();

    // *** IPersist ***
    STDMETHODIMP GetClassID(CLSID *pClassID);

    // *** IPersistFolder ***
    STDMETHODIMP Initialize(LPCITEMIDLIST pidl);

  private:
  // private members go here
};

HRESULT CSample::QueryInterface(REFIID riid, void **ppv)
{
    static QITAB rgqit[] =
    {
        QITABENT(CSample, IPersist),
        QITABENT(CSample, IPersistFolder)
        { 0 },
    };

    return QISearch(this, rgqit, IID_PPV_ARGS(&ppv));
}
```