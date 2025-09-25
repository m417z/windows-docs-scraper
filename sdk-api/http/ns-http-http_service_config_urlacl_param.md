# HTTP_SERVICE_CONFIG_URLACL_PARAM structure

## Description

The
**HTTP_SERVICE_CONFIG_URLACL_PARAM** structure is used to specify the permissions associated with a particular record in the URL namespace reservation store. It is a member of the
[HTTP_SERVICE_CONFIG_URLACL_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_urlacl_set) structure.

## Members

### `pStringSecurityDescriptor`

A pointer to a
[Security Descriptor Definition Language (SDDL) string](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-string-format) that contains the permissions associated with this URL namespace reservation record.

## Remarks

The security descriptor string pointed to by the **pStringSecurityDescriptor** member has the following elements:

An example of a security descriptor string is:

``` syntax
D:(A;;GX;;;S-1-0-0)(A;;GA;;;S-1-5-11)

```

## See also

[HTTP_SERVICE_CONFIG_URLACL_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_urlacl_set)

[Security Descriptor String Format](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-string-format)