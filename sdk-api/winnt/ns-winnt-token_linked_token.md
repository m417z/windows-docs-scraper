# TOKEN_LINKED_TOKEN structure

## Description

The **TOKEN_LINKED_TOKEN** structure contains a handle to a token. This token is linked to the token being queried by the [GetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-gettokeninformation) function or set by the [SetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-settokeninformation) function.

## Members

### `LinkedToken`

A handle to the linked token.

When you have finished using the handle, close it by calling the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function.