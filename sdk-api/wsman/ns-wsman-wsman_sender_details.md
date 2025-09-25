# WSMAN_SENDER_DETAILS structure

## Description

Specifies the client details for every inbound request.

## Members

### `senderName`

Specifies the user name of the client making the request. The content of this parameter varies depending on the type of authentication. The value of the *senderName* is formatted as follows:

| Authentication mechanism | Value of *senderName* |
| --- | --- |
| Windows Authentication | The domain and user name. |
| Basic Authentication | The user name specified. |
| Client Certificates | The subject of the certificate. |
| LiveID | The LiveID PUID as a string. |

### `authenticationMechanism`

Specifies a string that indicates which authentication mechanism was used by the client. The following values are predefined:

* Basic
* ClientCertificate

All other types are queried directly from the security package. For Internet Information Services (IIS) hosting, this string is retrieved from the IIS infrastructure.

### `certificateDetails`

A pointer to a [WSMAN_CERTIFICATE_DETAILS](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_certificate_details) structure that specifies the details of the client's certificate. This parameter is valid only if the *authenticationMechanism* is set to ClientCertificate.

### `clientToken`

Specifies the identity token of the user if a Windows security token is available for a user. This token will be used by the thread to impersonate this user for all calls into the plug-in.

**Note** Authorization plug-ins can change the user context and use a different impersonation token.

### `httpURL`

Specifies the HTTP URL of the inbound request.