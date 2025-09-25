# _BDCB_IMAGE_INFORMATION structure

## Description

The **BDCB_IMAGE_INFORMATION** structure describes information about a boot-start driver that is about to
be initialized, provided by Windows to a boot-start driver's
[BOOT_DRIVER_CALLBACK_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-boot_driver_callback_function) routine.

## Members

### `Classification`

An enumeration of type [**BDCB_CLASSIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_bdcb_classification) that the ELAM driver sets to specify the classification of the boot start image.

### `ImageFlags`

Bit flags that describe the image. The following values are defined.

| Value | Meaning |
| --- | --- |
| Bit 0 | The boot start image is a dependent DLL. |
| Bit 1 | The boot start image failed code integrity but load was allowed because of boot policy (code integrity not required on the platform, or code integrity disabled because of boot setting, debugging, or both). The symbolic name for bit 1 is `BDCB_IMAGEFLAGS_FAILED_CODE_INTEGRITY.` |
| Bits 2-31 | Do not use. Reserved. |

### `ImageName`

The name of the boot-start driver's binary image.

### `RegistryPath`

The path in the registry where the boot-start driver is registered.

### `CertificatePublisher`

The publisher of the image's certificate. If the image is not signed, the string is empty ("").

### `CertificateIssuer`

The issuer of the image's certificate. If the image is not signed, the string is empty ("").

### `ImageHash`

The Authenticode hash of the image, which can be calculated by using SignTool.exe (Sign Tool).

### `CertificateThumbprint`

The hash of the certificate of the signer to be signed. Run **certutil –dump x,cer** to view this value as "Signature Hash".

### `ImageHashAlgorithm`

The algorithm of the image hash. The following values are listed for reference.

| Value |
| --- |
| ALG_CLASS_HASH |
| ALG_CLASS_ANY |
| ALG_SID_MD5 |
| ALG_SID_SHA1 |
| ALG_SID_SHA_256 |
| ALG_SID_SHA_384 |
| ALG_SID_SHA_512 |
| CALG_MD5 |
| CALG_SHA1 |
| CALG_SHA_256 |
| CALG_SHA_384 |
| CALG_SHA_512 |

### `ThumbprintHashAlgorithm`

The algorithm of the certificate thumbprint. This member should be ignored if **CertificateThumbprint** is NULL.

### `ImageHashLength`

The length of data pointed to by the **ImageHash** member.

### `CertificateThumbprintLength`

The length of data pointed to by the **CertificateThumbprint** member.

## See also

[BDCB_CLASSIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_bdcb_classification)

[**BOOT_DRIVER_CALLBACK_FUNCTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-boot_driver_callback_function)

[**ALG_ID**](https://learn.microsoft.com/windows/win32/seccrypto/alg-id)