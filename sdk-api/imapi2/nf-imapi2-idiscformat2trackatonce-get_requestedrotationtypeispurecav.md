# IDiscFormat2TrackAtOnce::get_RequestedRotationTypeIsPureCAV

## Description

Retrieves the requested rotational-speed control type.

## Parameters

### `value` [out]

Requested rotational-speed control type. Is VARIANT_TRUE for constant angular velocity (CAV) rotational-speed control type. Otherwise, is VARIANT_FALSE for any other rotational-speed control type that the recorder supports.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## Remarks

This is the value specified in the most recent call to the [IDiscFormat2TrackAtOnce::SetWriteSpeed](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-setwritespeed) method.

## See also

[IDiscFormat2TrackAtOnce](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2trackatonce)

[IDiscFormat2TrackAtOnce::SetWriteSpeed](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-setwritespeed)

[IDiscFormat2TrackAtOnce::get_CurrentRotationTypeIsPureCAV](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-get_currentrotationtypeispurecav)