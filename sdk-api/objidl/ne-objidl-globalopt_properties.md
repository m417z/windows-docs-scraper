# GLOBALOPT_PROPERTIES enumeration

## Description

Identifies process-global options that you can set or query by using the [IGlobalOptions](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iglobaloptions) interface.

## Constants

### `COMGLB_EXCEPTION_HANDLING:1`

Defines COM exception-handling behavior.

### `COMGLB_APPID:2`

Sets the AppID for the process.

### `COMGLB_RPC_THREADPOOL_SETTING:3`

Sets the thread-pool behavior of the RPC runtime in the process.

### `COMGLB_RO_SETTINGS:4`

Used for miscellaneous settings.

### `COMGLB_UNMARSHALING_POLICY:5`

Defines the policy that's applied in the [CoUnmarshalInterface](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-counmarshalinterface) function.

### `COMGLB_PROPERTIES_RESERVED1:6`

### `COMGLB_PROPERTIES_RESERVED2:7`

### `COMGLB_PROPERTIES_RESERVED3:8`

## Remarks

The unmarshaling policy option **COMGLB_UNMARSHALING_POLICY** takes values from the [GLOBALOPT_UNMARSHALING_POLICY_VALUES](https://learn.microsoft.com/windows/win32/api/objidl/ne-objidl-globalopt_unmarshaling_policy_values) enumeration.

## See also

[CoUnmarshalInterface](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-counmarshalinterface)

[GLOBALOPT_UNMARSHALING_POLICY_VALUES](https://learn.microsoft.com/windows/win32/api/objidl/ne-objidl-globalopt_unmarshaling_policy_values)

[IGlobalOptions](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iglobaloptions)