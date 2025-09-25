# RADIUS_EXTENSION_CONTROL_BLOCK structure

## Description

**Note** Internet Authentication Service (IAS) was renamed Network Policy Server (NPS) starting with Windows Server 2008. The content of this topic applies to both IAS and NPS. Throughout the text, NPS is used to refer to all versions of the service, including the versions originally referred to as IAS.

The
**RADIUS_EXTENSION_CONTROL_BLOCK** structure provides information about the current RADIUS request. It also provides functions for obtaining the attributes associated with the request, and for setting the disposition of the request.

## Members

### `cbSize`

Specifies the size of the structure.

### `dwVersion`

Specifies the version of the structure.

### `repPoint`

Specifies a value of type
[RADIUS_EXTENSION_POINT](https://learn.microsoft.com/windows/desktop/api/authif/ne-authif-radius_extension_point) that indicates at what point in the request process
[RadiusExtensionProcess2](https://learn.microsoft.com/windows/desktop/api/authif/nc-authif-pradius_extension_process_2) was called.

### `rcRequestType`

Specifies a value of type
[RADIUS_CODE](https://learn.microsoft.com/windows/desktop/api/authif/ne-authif-radius_code) that specifies the type of RADIUS request received by the Internet Authentication Service server.

### `rcResponseType`

Specifies a value of type
[RADIUS_CODE](https://learn.microsoft.com/windows/desktop/api/authif/ne-authif-radius_code) that indicates the disposition of the RADIUS request.

### `GetRequest`

Pointer to the [GetRequest](https://learn.microsoft.com/previous-versions/ms688263(v=vs.85)) function provided by NPS. NPS sets the value of this member.

The
[GetRequest](https://learn.microsoft.com/previous-versions/ms688263(v=vs.85)) function returns the attributes received in the RADIUS request process and any internal attributes describing the request state.

The Extension DLL can modify the attributes in the RADIUS request. For example, if NPS is acting as a RADIUS proxy, an Extension DLL could filter which attributes are forwarded to the remote RADIUS server.

To modify the attributes, the Extension DLL uses the functions provided as members of the
[RADIUS_ATTRIBUTE_ARRAY](https://learn.microsoft.com/windows/desktop/api/authif/ns-authif-radius_attribute_array) structure.

#### This

Pointer to a
**RADIUS_EXTENSION_CONTROL_BLOCK** structure. NPS passes the Extension DLL a pointer to this structure when it calls the
[RadiusExtensionProcess2](https://learn.microsoft.com/windows/desktop/api/authif/nc-authif-pradius_extension_process_2) structure.

### `GetResponse`

Pointer to the [GetResponse](https://learn.microsoft.com/previous-versions/ms688270(v=vs.85)) function provided by NPS. NPS sets the value of this member.

The
[GetRequest](https://learn.microsoft.com/previous-versions/ms688263(v=vs.85)) function returns the attributes received in the RADIUS request process and any internal attributes describing the request state.

An Extension DLL can use
[GetResponse](https://learn.microsoft.com/previous-versions/ms688270(v=vs.85)) to retrieve and modify the attributes for any valid response type regardless of the request's current disposition. For example, an Extension DLL could
[set the response type](https://learn.microsoft.com/previous-versions/ms688462(v=vs.85)) to rcAccessAccept, but still add attributes to those returned in the case of an rcAccessReject. The response specified by the Extension DLL (rcAccessAccept in this example) could be overridden during further processing.

To modify the attributes, the Extension DLL uses the functions provided as members of the
[RADIUS_ATTRIBUTE_ARRAY](https://learn.microsoft.com/windows/desktop/api/authif/ns-authif-radius_attribute_array) structure.

#### This

Pointer to a
**RADIUS_EXTENSION_CONTROL_BLOCK** structure. NPS passes the Extension DLL a pointer to this structure when it calls the
[RadiusExtensionProcess2](https://learn.microsoft.com/windows/desktop/api/authif/nc-authif-pradius_extension_process_2) function.

#### rcResponseType

Specifies the response type. This parameter must be one of the values enumerated by the
[RADIUS_CODE](https://learn.microsoft.com/windows/desktop/api/authif/ne-authif-radius_code) enumeration type. Otherwise, the function fails, returning **NULL**.

### `SetResponseType`

Pointer to the [SetResponseType](https://learn.microsoft.com/previous-versions/ms688462(v=vs.85)) function provided by NPS. NPS sets the value of this member.

The
[SetResponseType](https://learn.microsoft.com/previous-versions/ms688462(v=vs.85)) function sets the final disposition of the request.

Note that the disposition set by the Extension DLL can be overridden during further processing. For example, the Extension DLL may set the response type to **rcAccessAccept**, but during further processing, the response can be changed to **rcAccessReject**.

#### This

Pointer to a
**RADIUS_EXTENSION_CONTROL_BLOCK** structure. NPS passes the Extension DLL a pointer to this structure when it calls the
[RadiusExtensionProcess2](https://learn.microsoft.com/windows/desktop/api/authif/nc-authif-pradius_extension_process_2) function.

#### rcResponseType

Specifies the response type. This parameter must be one of the values contained within the
[RADIUS_CODE](https://learn.microsoft.com/windows/desktop/api/authif/ne-authif-radius_code) enumerated type and is related to the **rcRequestType** member of the **RADIUS_EXTENSION_CONTROL_BLOCK** structure. If **rcRequestType** equals **rcAccessRequest**, this value may be **rcAccessAccept**, **rcAccessReject**, **rcAccessChallenge**, or **rcDiscard**. If **rcRequestType** equals **rcAccountingRequest**, this value can be **rcAccountingResponse** or **rcDiscard**. Otherwise, the function fails, returning **ERROR_INVALID_PARAMETER**.

## Remarks

The Extension DLL must not modify this structure. Changes to the array of attributes should be made by calling the functions provided as members of this structure.

NPS passes this structure to the Extension DLL when it calls the Extension DLL's implementation of
[RadiusExtensionProcess2](https://learn.microsoft.com/windows/desktop/api/authif/nc-authif-pradius_extension_process_2).

## See also

[GetRequest](https://learn.microsoft.com/previous-versions/ms688263(v=vs.85))

[GetResponse](https://learn.microsoft.com/previous-versions/ms688270(v=vs.85))

[RADIUS_ATTRIBUTE_ARRAY](https://learn.microsoft.com/windows/desktop/api/authif/ns-authif-radius_attribute_array)

[SetResponseType](https://learn.microsoft.com/previous-versions/ms688462(v=vs.85))