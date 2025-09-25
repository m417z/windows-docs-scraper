typedef enum _PCMCIA_CONTROLLER_CLASS {
  PcmciaInvalidControllerClass,
  PcmciaIntelCompatible,
  PcmciaCardBusCompatible,
  PcmciaElcController,
  PcmciaDatabook,
  PcmciaPciPcmciaBridge,
  PcmciaCirrusLogic,
  PcmciaTI,
  PcmciaTopic,
  PcmciaRicoh,
  PcmciaDatabookCB,
  PcmciaOpti,
  PcmciaTrid,
  PcmciaO2Micro,
  PcmciaNEC,
  PcmciaNEC_98
} PCMCIA_CONTROLLER_CLASS, *PPCMCIA_CONTROLLER_CLASS;