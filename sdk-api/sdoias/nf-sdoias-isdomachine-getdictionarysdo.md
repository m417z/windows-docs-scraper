# ISdoMachine::GetDictionarySDO

## Description

The
**GetDictionarySDO** method retrieves an interface for an attribute-dictionary SDO.

## Parameters

### `ppDictionarySDO` [out]

Pointer to an ISdoDictionary.

## Return value

If the method succeeds the return value is **S_OK**.

If the method fails, the return value is one of the following error codes.

## Remarks

Before calling this method, use the
[ISdoMachine::Attach](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdomachine-attach) method to attach to the SDO computer.

## See also

[ISdoDictionaryOld](https://learn.microsoft.com/windows/desktop/api/sdoias/nn-sdoias-isdodictionaryold)

[ISdoMachine](https://learn.microsoft.com/windows/desktop/api/sdoias/nn-sdoias-isdomachine)

[ISdoMachine::Attach](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdomachine-attach)