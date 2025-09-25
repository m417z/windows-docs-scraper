# IStillImageW::Initialize

## Description

The **IStillImage::Initialize** method initializes an instance of the COM object that defines the **IStillImage** COM interface. *This method is for internal system use only*.

## Parameters

### `hinst` [in]

Caller-supplied instance handle of the calling process. This handle is obtained by calling **GetModuleName**(NULL).

### `dwVersion`

Caller-supplied STI version number. This value must be STI_VERSION, defined in *Sti.h*.

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h.*

## Remarks

The **IStillImage::Initialize** method initializes the COM object instance that was created by calling [IStillImage::StiCreateInstance](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543804(v=vs.85)).

Because **IStillImage::Initialize** is called by **IStillImage::StiCreateInstance**, clients of the **IStillImage** COM interface do not typically call this method directly.