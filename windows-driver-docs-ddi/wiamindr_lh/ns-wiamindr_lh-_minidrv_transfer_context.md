# _MINIDRV_TRANSFER_CONTEXT structure

## Description

The MINIDRV_TRANSFER_CONTEXT structure is used to store image and other information needed for a memory-callback data transfer or a file data transfer.

## Members

### `lSize`

Specifies the size in bytes of this MINIDRV_TRANSFER_CONTEXT structure.

### `lWidthInPixels`

Specifies the width in pixels of the current image. The value of this member is derived from the [WIA_IPA_PIXELS_PER_LINE](https://learn.microsoft.com/windows-hardware/drivers/image/wia-ipa-pixels-per-line) common item property.

### `lLines`

Specifies the total number of lines (the number of horizontal rows of pixels) in the current image. The value of this member is derived from the [WIA_IPA_NUMBER_OF_LINES](https://learn.microsoft.com/windows-hardware/drivers/image/wia-ipa-number-of-lines) common item property.

### `lDepth`

Specifies the color depth value of the current image in bits per pixel. The value of this member is derived from the [WIA_IPA_DEPTH](https://learn.microsoft.com/windows-hardware/drivers/image/wia-ipa-depth) common item property.

### `lXRes`

Specifies the current horizontal resolution of the image in pixels per inch. The value of this member is derived from the [WIA_IPS_XRES](https://learn.microsoft.com/windows-hardware/drivers/image/wia-ips-xres) scanner item property.

### `lYRes`

Specifies the current vertical resolution of the image in pixels per inch. The value of this member is derived from the [WIA_IPS_YRES](https://learn.microsoft.com/windows-hardware/drivers/image/wia-ips-yres) scanner item property.

### `lCompression`

Specifies the type of compression used by the device. The value of this member is derived from the [WIA_IPA_COMPRESSION](https://learn.microsoft.com/windows-hardware/drivers/image/wia-ipa-compression) common item property.

### `guidFormatID`

Specifies a GUID that indicates the data format for the device. The value of this member is derived from the [WIA_IPA_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/image/wia-ipa-format) common item property.

### `tymed`

Specifies the type of data transfer. The data transfer specified can be either a memory-callback transfer (TYMED_CALLBACK or TYMED_MULTIPAGE_CALLBACK) or file transfer (TYMED_FILE or TYMED_MULTIPAGE_FILE). The value of this member is derived from the [WIA_IPA_TYMED](https://learn.microsoft.com/windows-hardware/drivers/image/wia-ipa-tymed) common item property.

This member conveys information related to that in the **bTransferDataCB** member. See **Remarks** for more information.

### `hFile`

Specifies the handle to the open file used during file transfers. The minidriver should not use this member. See **Remarks** for more information.

### `cbOffset`

Specifies the current offset in bytes of the next buffer location used during this transfer.

### `lBufferSize`

Specifies the total size of the transfer buffer.

### `lActiveBuffer`

Specifies which buffer is used for the current transfer. The value of this member must be in the range of 1 through **lNumBuffers**.

### `lNumBuffers`

Specifies the number of buffers available for data transfer. This value can currently be either 1 or 2.

### `pBaseBuffer`

Points to the start of the base transfer buffer.

### `pTransferBuffer`

Points to the start of the current transfer buffer. For a callback transfer in which double buffering is used, this member alternates between the two buffers, pointing to the beginning of the first buffer, and then to the beginning of the second, and so on.

### `bTransferDataCB`

Specifies whether a data transfer is a memory-callback transfer or a file transfer. This member is set to **TRUE** if the transfer is a memory-callback transfer, and **FALSE** if the transfer is a file transfer. For file transfers, the WIA service usually provides a callback routine, which enables the application to receive updates from the minidriver about the status of the file transfer. (The WIA service provides a callback routine if the application provides its own callback routine. See [IWiaMiniDrvCallback COM Interface](https://learn.microsoft.com/windows-hardware/drivers/image/iwiaminidrvcallback-com-interface) for details.) For file transfers, a minidriver should check the value stored in the **pIWiaMiniDrvCallBack** member. If that member is **NULL**, the WIA service does not provide a callback routine, so the driver must not attempt to call it. For memory-callback transfers, the WIA service always provides a callback.

This member conveys information related to that in the **tymed** member. See **Remarks** for more information.

### `bClassDrvAllocBuf`

Specifies whether the WIA service has allocated the transfer buffer. This value is **TRUE** if the WIA service allocated the buffer, and **FALSE** if not. In that case, it is the minidriver's responsibility to allocate the transfer buffer.

### `lClientAddress`

Specifies the address, in the client's address space, of the transfer. The minidriver must not change this value.

### `pIWiaMiniDrvCallBack`

Points to an [IWiaMiniDrvCallBack Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiaminidrvcallback) used for data or status callback transfer.

### `lImageSize`

Specifies the size, in bytes, of uncompressed bits in a single page.

### `lHeaderSize`

Specifies the size, in bytes, of image header data in a single page.

### `lItemSize`

Specifies the size, in bytes, of bits and header. This value can be zero if the item size is unknown before acquisition.

### `cbWidthInBytes`

Specifies the size, in bytes, of an image line.

### `lPage`

Specifies the page number of the current page when scanning a multipage TIFF image. Page numbering begins with zero.

### `lCurIfdOffset`

Specifies the image file directory (IFD) offset in the current page of a multipage TIFF image.

### `lPrevIfdOffset`

Specifies the image file directory (IFD) offset in the previous page of a multipage TIFF image.

## Remarks

The WIA service sets most of the members of this structure before it calls the minidriver's [IWiaMiniDrv::drvAcquireItemData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvacquireitemdata) method. If the minidriver calls [wiasGetImageInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasgetimageinformation), then that function fills in the remaining members of the MINIDRV_TRANSFER_CONTEXT passed to it.

Because the WIA service currently uses only the TYMED_FILE and TYMED_CALLBACK constants, the **tymed** and **bTransferDataCB** members store essentially the same information. For file transfers, when **bTransferDataCB** is set to **FALSE**, **tymed** is set to either TYMED_FILE or TYMED_MULTIPAGE_FILE. For memory-callback transfers, when **bTransferDataCB** is set to **TRUE**, **tymed** is set to either TYMED_CALLBACK or TYMED_MULTIPAGE_CALLBACK.

The **hFile** member is reserved for use solely by the WIA service. Rather than using this member for file transfers, the minidriver should instead write the data to a buffer, and then call [wiasWritePageBufToFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiaswritepagebuftofile) to complete the file transfer.

The minidriver obtains values from specific common or scanner item properties to set the members shown in the following table:

| Member | Set by |
| --- | --- |
| **lWidthInPixels** | [WIA_IPA_PIXELS_PER_LINE](https://learn.microsoft.com/windows-hardware/drivers/image/wia-ipa-pixels-per-line) |
| **lLines** | [WIA_IPA_NUMBER_OF_LINES](https://learn.microsoft.com/windows-hardware/drivers/image/wia-ipa-number-of-lines) |
| **lDepth** | [WIA_IPA_DEPTH](https://learn.microsoft.com/windows-hardware/drivers/image/wia-ipa-depth) |
| **lXRes** | [WIA_IPS_XRES](https://learn.microsoft.com/windows-hardware/drivers/image/wia-ips-xres) |
| **lYRes** | [WIA_IPS_YRES](https://learn.microsoft.com/windows-hardware/drivers/image/wia-ips-yres) |
| **lCompression** | [WIA_IPA_COMPRESSION](https://learn.microsoft.com/windows-hardware/drivers/image/wia-ipa-compression) |
| **guidFormatID** | [WIA_IPA_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/image/wia-ipa-format) |
| **tymed** | [WIA_IPA_TYMED](https://learn.microsoft.com/windows-hardware/drivers/image/wia-ipa-tymed) |

Usually, the minidriver sets the preceding structure members directly from the values of the item properties. An application or the minidriver will have set the item properties earlier. The WIA service fills in its service context, using the property values. The driver can use the values stored in this context for quick reference.

The WIA service sets the following structure members:

- **hFile**

- **bTransferDataCB**

- **bClassDrvAllocBuf**

Either the minidriver or the [wiasGetImageInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasgetimageinformation) service library function sets the following structure members:

- **lImageSize**

- **lHeaderSize**

- **lItemSize**

- **cbWidthInBytes**

The following members of this structure are used in data transfer callbacks. The WIA service or the minidriver sets these members. In several cases, the value stored in **bClassDrvAllocBuf** determines whether the WIA service or the minidriver sets the member.

| Member | Set by |
| --- | --- |
| **cbOffset** | Minidriver |
| **lBufferSize** | WIA service or minidriver. If **bClassDrvAllocBuf** is **TRUE**, the WIA service sets this member; otherwise, the minidriver sets it. |
| **lActiveBuffer** | WIA service. The minidriver must not modify this member. |
| **lNumBuffers** | WIA service. The minidriver must not modify this member. |
| **pBaseBuffer** | WIA service or minidriver. If **bClassDrvAllocBuf** is **TRUE**, the WIA service sets this member; otherwise, the minidriver sets it. |
| **pTransferBuffer** | WIA service or minidriver. If **bClassDrvAllocBuf** is **TRUE**, the WIA service sets this member; otherwise, the minidriver sets it. |
| **lClientAddress** | WIA service. The minidriver must not modify this member. |
| **pIWiaMiniDrvCallBack** | WIA service |

## See also

[IWiaMiniDrv::drvAcquireItemData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvacquireitemdata)

[IWiaMiniDrvCallBack::MiniDrvCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrvcallback-minidrvcallback)

[wiasGetImageInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasgetimageinformation)

[wiasWritePageBufToFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiaswritepagebuftofile)