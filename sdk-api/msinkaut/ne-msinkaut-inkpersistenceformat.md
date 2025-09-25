# InkPersistenceFormat enumeration

## Description

Specifies how ink is persisted.

## Constants

### `IPF_InkSerializedFormat:0`

Ink is persisted using ink serialized format (ISF).

This is the most compact persistent representation of ink. It can be embedded within a binary document format or placed directly on the Clipboard.

### `IPF_Base64InkSerializedFormat:1`

Ink is persisted by encoding the ISF as a base64 stream.

This format is provided so that ink can be encoded directly in an Extensible Markup Language (XML) or HTML file.

### `IPF_GIF:2`

Ink is persisted by using a Graphics Interchange Format (GIF) file that contains ISF as metadata that is embedded within the file.

This allows ink to be viewed in applications that are not ink-enabled and maintain its full ink fidelity when it returns to an ink-enabled application. This format is ideal when transporting ink content within an HTML file and making it usable by ink-enabled and ink-unaware applications.

### `IPF_Base64GIF:3`

Ink is persisted by using a base64 encoded fortified.

This GIF format is provided when ink is to be encoded directly in an XML or HTML file with later conversion into an image. A possible use of this would be in an XML format that is generated to contain all ink information and used as a way to generate HTML through Extensible Stylesheet Language Transformations (XSLT).

## See also

[InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class)

[Save Method [InkDisp Class]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-save)