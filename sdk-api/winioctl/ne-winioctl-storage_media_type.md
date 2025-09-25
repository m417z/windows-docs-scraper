# STORAGE_MEDIA_TYPE enumeration

## Description

Specifies various types of storage media. Parameters and members of type **STORAGE_MEDIA_TYPE** also accept values from the [MEDIA_TYPE](https://learn.microsoft.com/windows/win32/api/winioctl/ne-winioctl-media_type) enumeration type.

## Constants

### `DDS_4mm:0x20`

One of the following tape types: DAT, DDS1, DDS2, and so on.

### `MiniQic`

MiniQIC tape.

### `Travan`

Travan tape (TR-1, TR-2, TR-3, and so on).

### `QIC`

QIC tape.

### `MP_8mm`

An 8mm Exabyte metal particle tape.

### `AME_8mm`

An 8mm Exabyte advanced metal evaporative tape.

### `AIT1_8mm`

An 8mm Sony AIT1 tape.

### `DLT`

DLT compact tape (IIIxt or IV).

### `NCTP`

Philips NCTP tape.

### `IBM_3480`

IBM 3480 tape.

### `IBM_3490E`

IBM 3490E tape.

### `IBM_Magstar_3590`

IBM Magstar 3590 tape.

### `IBM_Magstar_MP`

IBM Magstar MP tape.

### `STK_DATA_D3`

STK data D3 tape.

### `SONY_DTF`

Sony DTF tape.

### `DV_6mm`

A 6mm digital videotape.

### `DMI`

Exabyte DMI tape (or compatible).

### `SONY_D2`

Sony D2S or D2L tape.

### `CLEANER_CARTRIDGE`

Cleaner (all drive types that support cleaners).

### `CD_ROM`

CD.

### `CD_R`

CD (write once).

### `CD_RW`

CD (rewriteable).

### `DVD_ROM`

DVD.

### `DVD_R`

DVD (write once).

### `DVD_RW`

DVD (rewriteable).

### `MO_3_RW`

Magneto-optical 3.5" (rewriteable).

### `MO_5_WO`

Magneto-optical 5.25" (write once).

### `MO_5_RW`

Magneto-optical 5.25" (rewriteable; not LIMDOW).

### `MO_5_LIMDOW`

Magneto-optical 5.25" (rewriteable; LIMDOW).

### `PC_5_WO`

Phase change 5.25" (write once)

### `PC_5_RW`

Phase change 5.25" (rewriteable)

### `PD_5_RW`

Phase change dual (rewriteable)

### `ABL_5_WO`

Ablative 5.25" (write once).

### `PINNACLE_APEX_5_RW`

Pinnacle Apex 4.6GB (rewriteable)

### `SONY_12_WO`

Sony 12" (write once).

### `PHILIPS_12_WO`

Philips/LMS 12" (write once).

### `HITACHI_12_WO`

Hitachi 12" (write once)

### `CYGNET_12_WO`

Cygnet/ATG 12" (write once)

### `KODAK_14_WO`

Kodak 14" (write once)

### `MO_NFR_525`

MO near field recording (Terastor)

### `NIKON_12_RW`

Nikon 12" (rewriteable).

### `IOMEGA_ZIP`

Iomega Zip.

### `IOMEGA_JAZ`

Iomega Jaz.

### `SYQUEST_EZ135`

Syquest EZ135.

### `SYQUEST_EZFLYER`

Syquest EzFlyer.

### `SYQUEST_SYJET`

Syquest SyJet.

### `AVATAR_F2`

Avatar 2.5" floppy.

### `MP2_8mm`

An 8mm Hitachi tape.

### `DST_S`

Ampex DST small tape.

### `DST_M`

Ampex DST medium tape.

### `DST_L`

Ampex DST large tape.

### `VXATape_1`

Ecrix 8mm tape.

### `VXATape_2`

Ecrix 8mm tape.

### `STK_EAGLE`

### `LTO_Ultrium`

LTO Ultrium (IBM, HP, Seagate).

### `LTO_Accelis`

LTO Accelis (IBM, HP, Seagate).

### `DVD_RAM`

DVD-RAM.

### `AIT_8mm`

AIT tape (AIT2 or higher).

### `ADR_1`

OnStream ADR1.

### `ADR_2`

OnStream ADR2.

### `STK_9940`

STK 9940.

### `SAIT`

SAIT tape.

**Windows Server 2003:** This is not supported before Windows Server 2003 with SP1.

### `VXATape`

Exabyte VXA tape.

**Windows Server 2008:** This is not supported before Windows Server 2008.

#### - STK_9840

STK 9840.

## See also

* [DEVICE_MEDIA_INFO](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_media_info)
* [MEDIA_TYPE](https://learn.microsoft.com/windows/win32/api/winioctl/ne-winioctl-media_type)
* [NTMS_MEDIATYPEINFORMATION](https://learn.microsoft.com/windows/win32/api/ntmsapi/ns-ntmsapi-ntms_mediatypeinformation)