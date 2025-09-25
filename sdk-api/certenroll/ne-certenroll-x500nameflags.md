# X500NameFlags enumeration

## Description

The **X500NameFlags** enumeration type specifies the display and [encoding](https://learn.microsoft.com/windows/win32/SecGloss/e-gly) characteristics of a distinguished name or [relative distinguished name](https://learn.microsoft.com/windows/win32/SecGloss/r-gly) (RDN). This enumeration is used to initialize an [IX500DistinguishedName](https://learn.microsoft.com/windows/win32/api/certenroll/nn-certenroll-ix500distinguishedname) object.

## Constants

### `XCN_CERT_NAME_STR_NONE:0`

Display characteristics are not identified.

### `XCN_CERT_SIMPLE_NAME_STR:1`

All [object identifiers](https://learn.microsoft.com/windows/win32/SecGloss/o-gly) (OIDs) are discarded. [Relative distinguished names](https://learn.microsoft.com/windows/win32/SecGloss/r-gly) (RDNs) are separated by commas followed by a space (, ). RDN attributes are separated by a plus sign enclosed within spaces ( + ).

### `XCN_CERT_OID_NAME_STR:2`

OIDs are separated from their associated attribute value by using an equal sign (=). RDNs are separated by a comma followed by a space (, ). RDN attributes are separated by a plus sign followed by a space (+ ).

### `XCN_CERT_X500_NAME_STR:3`

OIDs are converted to their [X.500](https://learn.microsoft.com/windows/win32/SecGloss/x-gly) key names. They are separated from their associated attribute value by using an equal sign (=). RDNs are separated by a comma followed by a space (, ). RDN attributes are separated by a plus sign followed by a space (+ ).

If an OID does not have a corresponding X.500 name, the OID is used with a prefix of OID. The RDN is enclosed within quotation marks (" ") if it contains leading or trailing white space or one of the following characters:

* Comma (,)
* Plus sign (+)
* Equal sign (=)
* Inch mark (")
* Line feed (\n)
* Less than sign (<)
* Greater than sign (>)
* Number sign (#)
* Semicolon (;)
* Embedded quotation mark (")

### `XCN_CERT_XML_NAME_STR:4`

OIDs are treated in the same manner as that used to convert XCN_CERT_X500_NAME_ST values except that they are formatted as a sequence of XML elements. This is shown in the following example:

```
<CN>cart.contoso.com</CN>
<OU>Terms of use at www.verisign.com (c)00</OU>
<OU rDNAttribute="true">IT Operations</OU>
<O>Contoso.com</O>
<L>New York</L>
<S>New York</S>
<C>US</C>
<RDN oid="1.2.3.4" type="string">name</RDN>
<RDN rDNAttribute="true" oid="1.2.1.3" type="encoded">0500</RDN>
<RDN oid="1.2.1.4" type="encoded">020135</RDN>
<RDN oid="1.2.2.5.3" type="octet">01FF7F</RDN>
```

The Unicode XML markup characters are escaped in the following manner. Characters greater than 0x7F are escaped by using character references (L"&#xXXXX;").

* & becomes L"&amp;"
* < becomes L"&lt;"
* > becomes L"&gt;"
* \' becomes L"&apos;"
* \" becomes L"&quot;"

### `XCN_CERT_NAME_STR_SEMICOLON_FLAG:0x40000000`

The comma (,) separator used between RDNs is replaced with a semicolon (;) character.

### `XCN_CERT_NAME_STR_NO_PLUS_FLAG:0x20000000`

The (+) separator used between RDN attributes is replaced with a single space character.

### `XCN_CERT_NAME_STR_NO_QUOTING_FLAG:0x10000000`

Inhibits the use of quotation marks for the XCN_CERT_X500_NAME_ST value.

### `XCN_CERT_NAME_STR_CRLF_FLAG:0x8000000`

The comma (,) separator used between RDNs is replaced with a carriage return/line feed (\r\n) sequence.

### `XCN_CERT_NAME_STR_COMMA_FLAG:0x4000000`

Specifies that the separator between RDNs is a comma (,).

### `XCN_CERT_NAME_STR_REVERSE_FLAG:0x2000000`

Specifies that the order of the RDNs that make up the distinguished name (DN) is reversed for encoding. The typical DN display order is CN=*name*,...,DC=*com*. Use this flag to change the encoding order to DC=*com*,...,CN=*name*. An [IX500DistinguishedName](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix500distinguishedname) object sets this flag by default unless you specify XCN_CERT_NAME_STR_FORWARD_FLAG.

### `XCN_CERT_NAME_STR_FORWARD_FLAG:0x1000000`

Use to undo the encoding order specified by setting the XCN_CERT_NAME_STR_REVERSE_FLAG value.

### `XCN_CERT_NAME_STR_AMBIGUOUS_SEPARATOR_FLAGS`

### `XCN_CERT_NAME_STR_DISABLE_IE4_UTF8_FLAG:0x10000`

Skips the initial attempt to decode T.61 Teletex character values to UTF-8 values. By default, T.61 values are initially decoded to UTF-8, but if UTF-8 decoding fails, the values are decoded as 8-bit characters.

### `XCN_CERT_NAME_STR_ENABLE_T61_UNICODE_FLAG:0x20000`

T.61 is used rather than Unicode character encoding for all characters less than 0xFF. LDAP, for example, uses T.61.

### `XCN_CERT_NAME_STR_ENABLE_UTF8_UNICODE_FLAG:0x40000`

UTF-8 is used for the distinguished name (DN) instead of Unicode character encoding.

### `XCN_CERT_NAME_STR_FORCE_UTF8_DIR_STR_FLAG:0x80000`

Forces the following X.500 keys to be encoded as UTF-8 strings rather than printable Unicode strings. The following is the list of the keys and their corresponding object identifiers (OIDs).

* CN - XCN_OID_COMMON_NAME
* G - XCN_OID_GIVEN_NAME
* GivenName - XCN_OID_GIVEN_NAME
* GN - XCN_OID_GIVEN_NAME
* I - XCN_OID_INITIALS
* Initials - XCN_OID_INITIALS
* L - XCN_OID_LOCALITY_NAME
* O - XCN_ORGANIZATION_NAME
* OU - XCN_OID_ORGANIZATIONAL_UNIT_NAME
* S - XCN_OID_STATE_OR_PROVINCE_NAME
* SN - XCN_ID_SUR_NAME
* ST - XCN_OID_STATE_OR_PROVINCE_NAME
* STREET - XCN_OID_STREET_ADDRESS
* T - XCN_OID_TITLE
* Title - XCN_OID_TITLE

### `XCN_CERT_NAME_STR_DISABLE_UTF8_DIR_STR_FLAG:0x100000`

Prevents forcing printable Unicode strings to be encoded by using UTF-8. Use when desired when XCN_CERT_NAME_STR_FORCE_UTF8_DIR_STR_FLAG is the default behavior.

### `XCN_CERT_NAME_STR_ENABLE_PUNYCODE_FLAG:0x200000`

Strings containing Unicode characters are transcoded to Punycode, a limited ASCII character subset that's used for Internet hostnames. This subset of ASCII characters consists of letters, digits, and hyphens.

### `XCN_CERT_NAME_STR_DS_ESCAPED:0x800000`

Escapes characters that are not allowed in distinguished names (DNs).

## See also

[CertEnroll Enumerations](https://learn.microsoft.com/windows/win32/SecCertEnroll/certenroll-enumerations)

[CertEnroll Interfaces](https://learn.microsoft.com/windows/win32/SecCertEnroll/certenroll-interfaces)

[IX500DistinguishedName](https://learn.microsoft.com/windows/win32/api/certenroll/nn-certenroll-ix500distinguishedname)