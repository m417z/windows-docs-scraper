## Description

The **StiCreateInstance** function creates an instance of the COM object that defines the **IStillImage** interface, and returns a pointer to the interface.

## Parameters

### `hinst`

Caller-supplied instance handle of the calling process. This handle is obtained by calling **GetModuleHandle**(**NULL**).

### `dwVer`

Caller-supplied STI version number. This value must be STI\_VERSION, defined in *Sti.h*.

### `ppSti`

Receives a pointer to the **IStillImage** interface.

### `punkOuter`

Optional, caller-supplied pointer to the "controlling unknown" for object aggregation. See the following **Remarks** section.

## Return value

If the operation succeeds, the method returns S\_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

For an application to use the **IStillImage** interface, it must first call the **StiCreateInstance** function to get a pointer to the interface. The pointer received in *ppSti* is used subsequently when calling **IStillImage** methods, as illustrated in the following example:

```cpp
PSTI pSti = NULL;
DWORD dwStiTotal = 0;     // total number of STI devices found
PVOID pStiInfo = NULL;    // STI device info buffer
HRESULT hres = StiCreateInstance(GetModuleHandle(NULL), STI_VERSION, &pSti, NULL);
...
hhes = pSti->GetDeviceList(0, 0, &dwStiTotal, &pStiInfo);
```

If you want to create an aggregate COM object that includes **IStillImage**, you must supply a pointer to the "controlling unknown" in *punkOuter*. In most cases you will not be creating an aggregate object, so *punkOuter* should be **NULL**. Object aggregation and the controlling unknown are described in the [Aggregation](https://learn.microsoft.com/windows/win32/com/aggregation) article and in the *Component Object Model Specification*.

## See also

[**IStillImage::Release**](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istillimagew-release)