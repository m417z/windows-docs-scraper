## Description

The **ACX_REQUEST_TYPE** enumeration describes the possible types of ACX requests.

## Constants

### `AcxRequestTypeUnknown`

The request type is unknown.

### `AcxRequestTypeAny`

Any Request types is possible.

### `AcxRequestTypeCreate`

This is a create request.

### `AcxRequestTypeProperty`

This is a property request.

### `AcxRequestTypeMethod`

This is a method request.

### `AcxRequestTypeEvent`

This is an event request.

### `AcxRequestTypeResetState`

This is a reset request.

### `AcxRequestTypeMax`

For internal validation, do not use.

## Remarks

### Example

Example usage is shown below.

```cpp

    ACX_REQUEST_TYPE reqType;

    {
        ACX_REQUEST_PARAMETERS  params;
        ACX_REQUEST_PARAMETERS_INIT(&params);
        AfxRequest::GetParameters(Request, &params);

        reqType = params.Type;
    }

    switch(reqType)
    {
    case AcxRequestTypeProperty:
        AfxHelper::DispatchProperty(GetObjectHandle(), Request, &m_Properties, recorder);
        break;

    case AcxRequestTypeMethod:
        AfxHelper::DispatchMethod(GetObjectHandle(), Request, &m_Methods, recorder);
        break;
...

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxrequest.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/)