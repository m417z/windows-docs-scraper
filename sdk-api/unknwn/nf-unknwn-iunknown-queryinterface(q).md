## Description

A helper function template that infers an interface identifier, and calls [QueryInterface(REFIID,void)](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(refiid_void)).

## Parameters

### `pp` [out]

Type: **[void](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)\*\***

The address of a pointer to an interface. For details, see the *ppvObject* parameter of [QueryInterface(REFIID,void)](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(refiid_void)).

## Return value

The function passes the return value back from [QueryInterface(REFIID,void)](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(refiid_void)).

## Syntax

```cpp
template<class Q>
HRESULT
STDMETHODCALLTYPE
QueryInterface(_COM_Outptr_ Q** pp)
{
    return QueryInterface(__uuidof(Q), (void **)pp);
}
```

The `class Q` template parameter is the type of a COM interface.

## See also

* [IUnknown interface](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)