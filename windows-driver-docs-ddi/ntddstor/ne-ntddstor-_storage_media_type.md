# STORAGE_MEDIA_TYPE enumeration (ntddstor.h)

## Description

The STORAGE_MEDIA_TYPE enumeration is used in conjunction with the [**IOCTL_STORAGE_GET_MEDIA_TYPES_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_get_media_types_ex) request to query the class driver for the types of media that a device supports.

## Constants

### `DDS_4mm`

Indicates a DAT DDS1 or DDS2 tape device (all vendors).

### `MiniQic`

Indicates a mini-QIC tape device.

### `Travan`

Indicates a Travan TR-1, 2 or 3 tape device.

### `QIC`

Indicates a QIC tape device.

### `MP_8mm`

Indicates an 8mm Exabyte metal particle tape device.

### `AME_8mm`

Indicates an 8mm Exabyte advanced metal tape device.

### `AIT1_8mm`

Indicates an 8mm Sony AIT tape device.

### `DLT`

Indicates a DLT compact IIIxt or IV tape device.

### `NCTP`

Indicates a Philips NCTP tape device.

### `IBM_3480`

Indicates an IBM 3480 tape device.

### `IBM_3490E`

Indicates an IBM 3490E tape device.

### `IBM_Magstar_3590`

Indicates an IBM Magstar 3590 tape device.

### `IBM_Magstar_MP`

Indicates an IBM Magstar MP tape device.

### `STK_DATA_D3`

Indicates an STK data D3 tape device.

### `SONY_DTF`

Indicates a Sony DTF tape device.

### `DV_6mm`

Indicates a 6mm digital video tape device.

### `DMI`

Indicates an Exabyte DMI tape device and compatible devices.

### `SONY_D2`

Indicates a Sony D2S or D2L tape device.

### `CLEANER_CARTRIDGE`

Indicates a drive type that supports drive cleaners.

### `CD_ROM`

Indicates a CD optical disk.

### `CD_R`

Indicates a CD-recordable (write once) optical disk.

### `CD_RW`

Indicates a CD-rewritable optical disk.

### `DVD_ROM`

Indicates a DVD-ROM optical disk.

### `DVD_R`

Indicates a DVD-recordable (write once) optical disk.

### `DVD_RW`

Indicates a DVD-rewritable optical disk.

### `MO_3_RW`

Indicates a 3.5" rewritable MO optical disk.

### `MO_5_WO`

Indicates a MO 5.25" write once optical disk.

### `MO_5_RW`

Indicates a MO 5.25" rewritable (not LIMDOW) optical disk.

### `MO_5_LIMDOW`

Indicates a MO 5.25" rewritable (LIMDOW) optical disk.

### `PC_5_WO`

Indicates a phase change 5.25" write once optical disk.

### `PC_5_RW`

Indicates a phase change 5.25" rewritable optical disk.

### `PD_5_RW`

Indicates a phase change dual rewritable optical disk.

### `ABL_5_WO`

Indicates an ablative 5.25" write once optical disk.

### `PINNACLE_APEX_5_RW`

Indicates a pinnacle apex 4.6-GB rewritable optical disk.

### `SONY_12_WO`

Indicates a Sony 12" write once optical disk.

### `PHILIPS_12_WO`

Indicates a Philips/LMS 12" write once optical disk.

### `HITACHI_12_WO`

Indicates a Hitachi 12" write once optical disk.

### `CYGNET_12_WO`

Indicates a Cygnet/ATG 12" write once optical disk.

### `KODAK_14_WO`

Indicates a Kodak 14" write once optical disk.

### `MO_NFR_525`

Indicates a near field recording (Terastor) optical disk.

### `NIKON_12_RW`

Indicates a Nikon 12" rewritable optical disk.

### `IOMEGA_ZIP`

Indicates Iomega zip magnetic disk device.

### `IOMEGA_JAZ`

Indicates an Iomega Jaz magnetic disk device.

### `SYQUEST_EZ135`

Indicates a Syquest EZ135 magnetic disk device.

### `SYQUEST_EZFLYER`

Indicates a Syquest EzFlyer magnetic disk device.

### `SYQUEST_SYJET`

Indicates a Syquest SyJet magnetic disk device.

### `AVATAR_F2`

Indicates a 2.5" Floppy device.

### `MP2_8mm`

Indicates an 8mm Hitachi tape device.

### `DST_S`

Indicates a type DST Ampex small tape device.

### `DST_M`

Indicates a type DST Ampex medium tape device.

### `DST_L`

Indicates a type DST Ampex large tape device.

### `VXATape_1`

Indicates an 8mm Ecrix tape device.

### `VXATape_2`

Indicates an 8mm Ecrix tape device.

### `STK_EAGLE`

### `LTO_Ultrium`

Indicates an IBM, HP, or Seagate LTO Ultrium device.

### `LTO_Accelis`

Indicates an IBM, HP, or Seagate LTO Accelis

### `DVD_RAM`

Indicates a DVD-RAM optical device.

### `AIT_8mm`

Indicates an AIT2 or higher 8mm tape device.

### `ADR_1`

Indicates an on-stream ADR media type device.

### `ADR_2`

Indicates an on-stream ADR media type device.

### `STK_9940`

STK 9940

### `SAIT`

SAIT Tapes

### `VXATape`

VXA (Ecrix 8mm) Tape

## See also

[**DEVICE_MEDIA_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_media_info)

[**GET_MEDIA_TYPES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_get_media_types)

[**IOCTL_STORAGE_GET_MEDIA_TYPES_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_get_media_types_ex)