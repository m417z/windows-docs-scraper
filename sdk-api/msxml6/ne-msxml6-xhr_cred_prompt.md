# XHR_CRED_PROMPT enumeration

## Description

Specifies whether to allow credential prompts to the user for authentication.

## Constants

### `XHR_CRED_PROMPT_ALL:0`

Allow all credential prompts for authentication.

This setting allows credential prompts in response to requests from the proxy or the server.

### `XHR_CRED_PROMPT_NONE:0x1`

Disable all credential prompts for authentication. This setting disables any credential prompts in response to requests from the proxy or the server.

### `XHR_CRED_PROMPT_PROXY:0x2`

Allow credential prompts for authentication only in response to requests from the proxy.

This setting disables any credential prompts in response to requests from the server.

## See also

[SetProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2-setproperty)