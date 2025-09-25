## Description

Queries whether the specified Key System and, optionally, content type are supported.

## Parameters

### `keySystem`

An **LPCWSTR** specifying the Key System for which support is being queried.

### `contentType`

Optional. An **LPCWSTR** specifying the content type for which support is being queried. See the **Remarks** section for more information about this parameter.

## Return value

True if the specified Key System and content type are supported; otherwise, false.

## Remarks

> [!NOTE]
> The *contentType* parameter is ignored by PlayReady, and so for that content protection system the return value only indicates whether the specified Key System is supported. If the specified Key System is supported, the method will return true, regardless of what value is specified for *contentType*. The *contentType* parameter may also be ignored by other content protection systems.

For information about Key Systems, see the Encrypted Media Extension specification's [Key System](https://www.w3.org/TR/2017/REC-encrypted-media-20170918/#key-system)

## See also