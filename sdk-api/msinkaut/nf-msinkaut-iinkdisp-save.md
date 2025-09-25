# IInkDisp::Save

## Description

Converts the ink to the specified [InkPersistenceFormat](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkpersistenceformat), saves the ink by using the specified [InkPersistenceCompressionMode](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkpersistencecompressionmode), and returns the binary data in an array of bytes.

## Parameters

### `PersistenceFormat` [in, optional]

Optional. Sets one of the [InkPersistenceFormat](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkpersistenceformat) values that indicates the format of the persisted ink. The default value is InkSerializedFormat.

| Name | Description |
| --- | --- |
| **InkSerializedFormat** | Ink is persisted using ink serialized format (ISF).<br><br>This is the most compact persistent representation of ink. It can be embedded within a binary document format or placed directly on the Clipboard. This is the default value. |
| **Base64InkSerializedFormat** | Ink is persisted by encoding the ISF as a base64 stream.<br><br>This format is provided so that ink can be encoded directly in an Extensible Markup Language (XML) or HTML file. |
| **Gif** | Ink is persisted by using a Graphics Interchange Format (GIF) file that contains ISF as metadata that is embedded within the file. <br><br>This allows ink to be viewed in applications that are not ink-enabled and maintain its full ink fidelity when it returns to an ink-enabled application. This format is ideal when transporting ink content within an HTML file and making it usable by ink-enabled and ink-unaware applications. |
| **Base64Gif** | Ink is persisted by using a base64 encoded fortified. <br><br>This GIFformat is provided when ink is to be encoded directly in an XML or HTML file with later conversion into an image. A possible use of this would be in an XML format that is generated to contain all ink information and used as a way to generate HTML through Extensible Stylesheet Language Transformations (XSLT). |

### `CompressionMode` [in, optional]

Optional. One of the [InkPersistenceCompressionMode](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkpersistencecompressionmode) values that specifies the compression mode of the persisted ink.
The default value is IPCM_Default.

| Name | Description |
| --- | --- |
| **IPCM_Default** | Is used when the best tradeoff between save-time and storage for the typical application is needed. |
| **IPCM_MaximumCompression** | Is used when minimizing storage space is more important than how fast the ink is saved. |
| **IPCM_NoCompression** | Is used when save-time is more important than the amount of storage space used and when compatibility between versions is important. |

### `Data` [out, retval]

When this method returns, contains the byte array that contains the persisted ink.

For more information about the VARIANT structure, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_INVALIDARG** | Invalid compression mode. |
| **E_OUTOFMEMORY** | Cannot allocate byte array. |
| **E_UNEXPECTED** | Occurs if you attempt to save an empty Ink object in GIF format. |

## Remarks

Attempting to save an empty [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object in GIF format generates an error.

**Note** When calling the **Save** method with an [InkPersistenceFormat](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkpersistenceformat) value of **Base64InkSerializedFormat**, the return value is a **NULL** -terminated byte array. To write the saved ink to an XML file, first remove the last byte from the array before converting the array to 8-bit Unicode Transformation Format (UTF-8) encoded string.

## See also

[IInkDisp](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkdisp)

[InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class)

[InkPersistenceCompressionMode Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkpersistencecompressionmode)

[InkPersistenceFormat Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkpersistenceformat)

[Load Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-load)