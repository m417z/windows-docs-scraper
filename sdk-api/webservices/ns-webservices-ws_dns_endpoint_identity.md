# WS_DNS_ENDPOINT_IDENTITY structure

## Description

Type for specifying an endpoint identity represented by a DNS name.

## Members

### `identity`

The base type from which this type and all other endpoint identity types derive.

### `dns`

The DNS name of the endpoint that is represented by this endpoint identity.
The acceptable forms of the name are as defined by [RFC 1035](https://datatracker.ietf.org/doc/html/rfc1035).
In particular, they include both a simple machine name as well as a fully qualified domain name (FQDN).