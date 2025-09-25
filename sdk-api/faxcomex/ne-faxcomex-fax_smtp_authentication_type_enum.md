# FAX_SMTP_AUTHENTICATION_TYPE_ENUM enumeration

## Description

The **FAX_SMTP_AUTHENTICATION_TYPE_ENUM** enumeration defines the configuration options for delivery receipts sent through email.

## Constants

### `fsatANONYMOUS:0`

The server sends fax transmission receipts using a nonauthenticated SMTP protocol.

### `fsatBASIC`

The server sends fax transmission receipts using a basic (plain text) authenticated SMTP protocol.

### `fsatNTLM`

The server sends fax transmission receipts using an NTLM-authenticated SMTP protocol.

## See also

[IFaxReceiptOptions::get_AuthenticationType](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxreceiptoptions-authenticationtype-vb)