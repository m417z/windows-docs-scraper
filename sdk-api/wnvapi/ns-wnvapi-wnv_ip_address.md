# WNV_IP_ADDRESS structure

## Description

Defines an IP address object.

## Members

### `IP`

An IP version 4 (IPv4) or IP version 6 (IPv6) address object.

### `IP.v4`

Type: **IN_ADDR**

An IPv4 address.

### `IP.v6`

Type: **IN6_ADDR**

An IPv6 address.

### `IP.Addr`

Type: **UCHAR[sizeof(IN6_ADDR)]**

An array of bytes that contains the IP address.

## Remarks

The **ADDRESS_FAMILY** value is always specified separately in the structures that contain this IP address object.