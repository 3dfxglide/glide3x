/*
** THIS SOFTWARE IS SUBJECT TO COPYRIGHT PROTECTION AND IS OFFERED ONLY
** PURSUANT TO THE 3DFX GLIDE GENERAL PUBLIC LICENSE. THERE IS NO RIGHT
** TO USE THE GLIDE TRADEMARK WITHOUT PRIOR WRITTEN PERMISSION OF 3DFX
** INTERACTIVE, INC. A COPY OF THIS LICENSE MAY BE OBTAINED FROM THE 
** DISTRIBUTOR OR BY CONTACTING 3DFX INTERACTIVE INC(info@3dfx.com). 
** THIS PROGRAM IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER 
** EXPRESSED OR IMPLIED. SEE THE 3DFX GLIDE GENERAL PUBLIC LICENSE FOR A
** FULL TEXT OF THE NON-WARRANTY PROVISIONS.  
** 
** USE, DUPLICATION OR DISCLOSURE BY THE GOVERNMENT IS SUBJECT TO
** RESTRICTIONS AS SET FORTH IN SUBDIVISION (C)(1)(II) OF THE RIGHTS IN
** TECHNICAL DATA AND COMPUTER SOFTWARE CLAUSE AT DFARS 252.227-7013,
** AND/OR IN SIMILAR OR SUCCESSOR CLAUSES IN THE FAR, DOD OR NASA FAR
** SUPPLEMENT. UNPUBLISHED RIGHTS RESERVED UNDER THE COPYRIGHT LAWS OF
** THE UNITED STATES.  
** 
** COPYRIGHT 3DFX INTERACTIVE, INC. 1999, ALL RIGHTS RESERVED
**
** $Header$
** $Log$
** 
** 3     4/06/99 3:36p Dow
** Alt tab stuff
** 
** 
** 1     3/04/98 4:13p Dow
**
*/


char * ioRegNames[] = {     
  "status",
  "pciInit0",
  "sipMonitor",
  "lfbMemoryConfig",
  "miscInit0",
  "miscInit1",
  "dramInit0",
  "dramInit1",
  "agpInit",
  "tmuGbeInit",
  "vgaInit0",
  "vgaInit1",
  "dramCommand",
  "dramData",
  "reservedZ0",
  "reservedZ1",
  "pllCtrl0",
  "pllCtrl1",
  "pllCtrl2",
  "dacMode",
  "dacAddr",
  "dacData",
  "vidMaxRGBDelta",
  "vidProcCfg",
  "hwCurPatAddr",
  "hwCurLoc",
  "hwCurC0",
  "hwCurC1",
  "vidInFormat",
  "vidInStatus",
  "vidSerialParallelPort",
  "vidInXDecimDeltas",
  "vidInDecimInitErrs",
  "vidInYDecimDeltas",
  "vidPixelBufThold",
  "vidChromaMin",
  "vidChromaMax",
  "vidCurrentLine",
  "vidScreenSize",
  "vidOverlayStartCoords",
  "vidOverlayEndScreenCoord",
  "vidOverlayDudx",
  "vidOverlayDudxOffsetSrcWidth",
  "vidOverlayDvdy",
  "vgaRegister00",
  "vgaRegister01",
  "vgaRegister02",
  "vgaRegister03",
  "vgaRegister04",
  "vgaRegister05",
  "vgaRegister06",
  "vgaRegister07",
  "vgaRegister08",
  "vgaRegister09",
  "vgaRegister0a",
  "vgaRegister0b",
  "vidOverlayDvdyOffset",
  "vidDesktopStartAddr",
  "vidDesktopOverlayStride",
  "vidInAddr0",
  "vidInAddr1",
  "vidInAddr2",
  "vidInStride",
  "vidCurrOverlayStartAddr"
};

char *cmdAGPRegNames[] = {
  // AGP
  "agpReqSize",
  "hostAddrLow",
  "hostAddrHigh",
  "graphicsAddr",
  "graphicsStride",
  "moveCMD",
  "reservedL0",
  "reservedL1",
  // CMD FIFO 0
  "baseAddrL0",
  "baseSize0",
  "bump0",
  "readPtrL0",
  "readPtrH0",
  "aMin0",
  "unusedA0",
  "aMax0",
  "unusedB0",
  "depth0",
  "holeCount0",
  "reserved0",
  // CMD FIFO 1
  "baseAddrL1",
  "baseSize1",
  "bump1",
  "readPtrL1",
  "readPtrH1",
  "aMin1",
  "unusedA1",
  "aMax1",
  "unusedB1",
  "depth1",
  "holeCount1",
  "reserved1",
  "cmdFifoThresh",

  "reservedO00",
  "reservedO01",
  "reservedO02",
  "reservedO03",
  "reservedO04",
  "reservedO05",
  "reservedO06",
  "reserved007",
  "reservedP00",
  "reservedP01",
  "reservedP02",
  "reservedP03",
  "reservedP04",
  "reservedP05",
  "reservedP06",
  "reservedP07",
  "reservedQ00",
  "reservedQ01",
  "reservedQ02",
  "reservedQ03",
  "reservedQ04",
  "reservedQ05",
  "reservedQ06",
  "reservedQ07",
  "reservedR00",
  "reservedR01",
  "reservedR02",
  "reservedR03",
  "reservedR04",
  "reservedR05",
  "reservedR06",
  "reservedR07",

  // misc
  "yuvBaseAddr",
  "yuvStride"
};

char *waxRegNames[] = {
  "status",
  "unused0",
  "clip0min",
  "clip0max",
  "dstBaseAddr",
  "dstFormat",
  "srcColorkeyMin",
  "srcColorkeyMax",
  "dstColorkeyMin",
  "dstColorkeyMax",
  "bresError0",
  "bresError1",
  "rop",
  "srcBaseAddr",
  "commandEx",
  "lineStipple",
  "lineStyle",
  "pattern0alias",
  "pattern1alias",
  "clip1min",
  "clip1max",
  "srcFormat",
  "srcSize",
  "srcXY",
  "colorBack",
  "colorFore",
  "dstSize",
  "dstXY",
  "command",
  "reserved00",
  "reserved01",
  "reserved02",
  "launch00",
  "launch01",
  "launch02",
  "launch03",
  "launch04",
  "launch05",
  "launch06",
  "launch07",
  "launch08",
  "launch09",
  "launch0A",
  "launch0B",
  "launch0C",
  "launch0D",
  "launch0E",
  "launch0F",
  "launch10",
  "launch11",
  "launch12",
  "launch13",
  "launch14",
  "launch15",
  "launch16",
  "launch17",
  "launch18",
  "launch19",
  "launch1A",
  "launch1B",
  "launch1C",
  "launch1D",
  "launch1E",
  "launch1F",
  "colorPattern00",
  "colorPattern01",
  "colorPattern02",
  "colorPattern03",
  "colorPattern04",
  "colorPattern05",
  "colorPattern06",
  "colorPattern07",
  "colorPattern08",
  "colorPattern09",
  "colorPattern0A",
  "colorPattern0B",
  "colorPattern0C",
  "colorPattern0D",
  "colorPattern0E",
  "colorPattern0F",
  "colorPattern10",
  "colorPattern11",
  "colorPattern12",
  "colorPattern13",
  "colorPattern14",
  "colorPattern15",
  "colorPattern16",
  "colorPattern17",
  "colorPattern18",
  "colorPattern19",
  "colorPattern1A",
  "colorPattern1B",
  "colorPattern1C",
  "colorPattern1D",
  "colorPattern1E",
  "colorPattern1F",
  "colorPattern20",
  "colorPattern21",
  "colorPattern22",
  "colorPattern23",
  "colorPattern24",
  "colorPattern25",
  "colorPattern26",
  "colorPattern27",
  "colorPattern28",
  "colorPattern29",
  "colorPattern2A",
  "colorPattern2B",
  "colorPattern2C",
  "colorPattern2D",
  "colorPattern2E",
  "colorPattern2F",
  "colorPattern30",
  "colorPattern31",
  "colorPattern32",
  "colorPattern33",
  "colorPattern34",
  "colorPattern35",
  "colorPattern36",
  "colorPattern37",
  "colorPattern38",
  "colorPattern39",
  "colorPattern3A",
  "colorPattern3B",
  "colorPattern3C",
  "colorPattern3D",
  "colorPattern3E",
  "colorPattern3F",
  "colorTransLut000",
  "colorTransLut001",
  "colorTransLut002",
  "colorTransLut003",
  "colorTransLut004",
  "colorTransLut005",
  "colorTransLut006",
  "colorTransLut007",
  "colorTransLut008",
  "colorTransLut009",
  "colorTransLut00A",
  "colorTransLut00B",
  "colorTransLut00C",
  "colorTransLut00D",
  "colorTransLut00E",
  "colorTransLut00F",
  "colorTransLut010",
  "colorTransLut011",
  "colorTransLut012",
  "colorTransLut013",
  "colorTransLut014",
  "colorTransLut015",
  "colorTransLut016",
  "colorTransLut017",
  "colorTransLut018",
  "colorTransLut019",
  "colorTransLut01A",
  "colorTransLut01B",
  "colorTransLut01C",
  "colorTransLut01D",
  "colorTransLut01E",
  "colorTransLut01F",
  "colorTransLut020",
  "colorTransLut021",
  "colorTransLut022",
  "colorTransLut023",
  "colorTransLut024",
  "colorTransLut025",
  "colorTransLut026",
  "colorTransLut027",
  "colorTransLut028",
  "colorTransLut029",
  "colorTransLut02A",
  "colorTransLut02B",
  "colorTransLut02C",
  "colorTransLut02D",
  "colorTransLut02E",
  "colorTransLut02F",
  "colorTransLut030",
  "colorTransLut031",
  "colorTransLut032",
  "colorTransLut033",
  "colorTransLut034",
  "colorTransLut035",
  "colorTransLut036",
  "colorTransLut037",
  "colorTransLut038",
  "colorTransLut039",
  "colorTransLut03A",
  "colorTransLut03B",
  "colorTransLut03C",
  "colorTransLut03D",
  "colorTransLut03E",
  "colorTransLut03F",
  "colorTransLut040",
  "colorTransLut041",
  "colorTransLut042",
  "colorTransLut043",
  "colorTransLut044",
  "colorTransLut045",
  "colorTransLut046",
  "colorTransLut047",
  "colorTransLut048",
  "colorTransLut049",
  "colorTransLut04A",
  "colorTransLut04B",
  "colorTransLut04C",
  "colorTransLut04D",
  "colorTransLut04E",
  "colorTransLut04F",
  "colorTransLut050",
  "colorTransLut051",
  "colorTransLut052",
  "colorTransLut053",
  "colorTransLut054",
  "colorTransLut055",
  "colorTransLut056",
  "colorTransLut057",
  "colorTransLut058",
  "colorTransLut059",
  "colorTransLut05A",
  "colorTransLut05B",
  "colorTransLut05C",
  "colorTransLut05D",
  "colorTransLut05E",
  "colorTransLut05F",
  "colorTransLut060",
  "colorTransLut061",
  "colorTransLut062",
  "colorTransLut063",
  "colorTransLut064",
  "colorTransLut065",
  "colorTransLut066",
  "colorTransLut067",
  "colorTransLut068",
  "colorTransLut069",
  "colorTransLut06A",
  "colorTransLut06B",
  "colorTransLut06C",
  "colorTransLut06D",
  "colorTransLut06E",
  "colorTransLut06F",
  "colorTransLut070",
  "colorTransLut071",
  "colorTransLut072",
  "colorTransLut073",
  "colorTransLut074",
  "colorTransLut075",
  "colorTransLut076",
  "colorTransLut077",
  "colorTransLut078",
  "colorTransLut079",
  "colorTransLut07A",
  "colorTransLut07B",
  "colorTransLut07C",
  "colorTransLut07D",
  "colorTransLut07E",
  "colorTransLut07F",
  "colorTransLut080",
  "colorTransLut081",
  "colorTransLut082",
  "colorTransLut083",
  "colorTransLut084",
  "colorTransLut085",
  "colorTransLut086",
  "colorTransLut087",
  "colorTransLut088",
  "colorTransLut089",
  "colorTransLut08A",
  "colorTransLut08B",
  "colorTransLut08C",
  "colorTransLut08D",
  "colorTransLut08E",
  "colorTransLut08F",
  "colorTransLut090",
  "colorTransLut091",
  "colorTransLut092",
  "colorTransLut093",
  "colorTransLut094",
  "colorTransLut095",
  "colorTransLut096",
  "colorTransLut097",
  "colorTransLut098",
  "colorTransLut099",
  "colorTransLut09A",
  "colorTransLut09B",
  "colorTransLut09C",
  "colorTransLut09D",
  "colorTransLut09E",
  "colorTransLut09F",
  "colorTransLut0A0",
  "colorTransLut0A1",
  "colorTransLut0A2",
  "colorTransLut0A3",
  "colorTransLut0A4",
  "colorTransLut0A5",
  "colorTransLut0A6",
  "colorTransLut0A7",
  "colorTransLut0A8",
  "colorTransLut0A9",
  "colorTransLut0AA",
  "colorTransLut0AB",
  "colorTransLut0AC",
  "colorTransLut0AD",
  "colorTransLut0AE",
  "colorTransLut0AF",
  "colorTransLut0B0",
  "colorTransLut0B1",
  "colorTransLut0B2",
  "colorTransLut0B3",
  "colorTransLut0B4",
  "colorTransLut0B5",
  "colorTransLut0B6",
  "colorTransLut0B7",
  "colorTransLut0B8",
  "colorTransLut0B9",
  "colorTransLut0BA",
  "colorTransLut0BB",
  "colorTransLut0BC",
  "colorTransLut0BD",
  "colorTransLut0BE",
  "colorTransLut0BF",
  "colorTransLut0C0",
  "colorTransLut0C1",
  "colorTransLut0C2",
  "colorTransLut0C3",
  "colorTransLut0C4",
  "colorTransLut0C5",
  "colorTransLut0C6",
  "colorTransLut0C7",
  "colorTransLut0C8",
  "colorTransLut0C9",
  "colorTransLut0CA",
  "colorTransLut0CB",
  "colorTransLut0CC",
  "colorTransLut0CD",
  "colorTransLut0CE",
  "colorTransLut0CF",
  "colorTransLut0D0",
  "colorTransLut0D1",
  "colorTransLut0D2",
  "colorTransLut0D3",
  "colorTransLut0D4",
  "colorTransLut0D5",
  "colorTransLut0D6",
  "colorTransLut0D7",
  "colorTransLut0D8",
  "colorTransLut0D9",
  "colorTransLut0DA",
  "colorTransLut0DB",
  "colorTransLut0DC",
  "colorTransLut0DD",
  "colorTransLut0DE",
  "colorTransLut0DF",
  "colorTransLut0E0",
  "colorTransLut0E1",
  "colorTransLut0E2",
  "colorTransLut0E3",
  "colorTransLut0E4",
  "colorTransLut0E5",
  "colorTransLut0E6",
  "colorTransLut0E7",
  "colorTransLut0E8",
  "colorTransLut0E9",
  "colorTransLut0EA",
  "colorTransLut0EB",
  "colorTransLut0EC",
  "colorTransLut0ED",
  "colorTransLut0EE",
  "colorTransLut0EF",
  "colorTransLut0F0",
  "colorTransLut0F1",
  "colorTransLut0F2",
  "colorTransLut0F3",
  "colorTransLut0F4",
  "colorTransLut0F5",
  "colorTransLut0F6",
  "colorTransLut0F7",
  "colorTransLut0F8",
  "colorTransLut0F9",
  "colorTransLut0FA",
  "colorTransLut0FB",
  "colorTransLut0FC",
  "colorTransLut0FD",
  "colorTransLut0FE",
  "colorTransLut0FF"
};

char *sstRegNames[] = {
  "status",
  "intrCtrl",
  "vAx",
  "vAy",
  "vBx",
  "vBy",
  "vCx",
  "vCy",

  "r",
  "g",
  "b",
  "z",
  "a",
  "s",
  "t",
  "w",

  "drdx",
  "dgdx",
  "dbdx",
  "dzdx",
  "dadx",
  "dsdx",
  "dtdx",
  "dwdx",

  "drdy",
  "dgdy",
  "dbdy",
  "dzdy",
  "dady",
  "dsdy",
  "dtdy",
  "dwdy",

  "triangleCMD",
  "reservedA",
  "FvA",
  "FvA",
  "FvB",
  "FvB",
  "FvC",
  "FvC",

  "Fr",
  "Fg",
  "Fb",
  "Fz",
  "Fa",
  "Fs",
  "Ft",
  "Fw",

  "Fdrdx",
  "Fdgdx",
  "Fdbdx",
  "Fdzdx",
  "Fdadx",
  "Fdsdx",
  "Fdtdx",
  "Fdwdx",

  "Fdrdy",
  "Fdgdy",
  "Fdbdy",
  "Fdzdy",
  "Fdady",
  "Fdsdy",
  "Fdtdy",
  "Fdwdy",

  "FtriangleCMD",
  "fbzColorPath",
  "fogMode",
  "alphaMode",
  "fbzMode",
  "lfbMode",
  "clipLeftRight",
  "clipBottomTop",

  "nopCMD",
  "fastfillCMD",
  "swapbufferCMD",
  "fogColor",
  "zaColor",
  "chromaKey",
  "chromaRange",
  "userIntrCmd",

  "stipple",
  "c0",
  "c1",
  "fbiPixelsIn",
  "fbiChromaFail",
  "fbiZfuncFail",
  "fbiAfuncFail",
  "fbiPixelsOut",

  "fogTable00",
  "fogTable01",
  "fogTable02",
  "fogTable03",
  "fogTable04",
  "fogTable05",
  "fogTable06",
  "fogTable07",
  "fogTable08",
  "fogTable09",
  "fogTable0A",
  "fogTable0B",
  "fogTable0C",
  "fogTable0D",
  "fogTable0E",
  "fogTable0F",
  "fogTable10",
  "fogTable11",
  "fogTable12",
  "fogTable13",
  "fogTable14",
  "fogTable15",
  "fogTable16",
  "fogTable17",
  "fogTable18",
  "fogTable19",
  "fogTable1A",
  "fogTable1B",
  "fogTable1C",
  "fogTable1D",
  "fogTable1E",
  "fogTable1F",

  "reservedB0",
  "reservedB1",
  "reservedB2",

  "colBufferAddr",
  "colBufferStride",
  "auxBufferAddr",
  "auxBufferStride",
  "reservedC",

  "clipLeftRight1",
  "clipBottomTop1",
  "reservedD00",
  "reservedD01",
  "reservedD02",
  "reservedD03",
  "reservedD04",
  "reservedD05",

  "reservedE00",
  "reservedE01",
  "reservedE02",
  "reservedE03",
  "reservedE04",
  "reservedE05",

  "reservedF0",
  "reservedF1",
  "reservedF2",
  "swapBufferPend",
  "leftOverlayBuf",
  "rightOverlayBuf",
  "fbiSwapHistory",
  "fbiTrianglesOut",

  "sSetupMode",
  "sVx",
  "sVy",
  "sARGB",
  "sRed",
  "sGreen",
  "sBlue",
  "sAlpha",

  "sVz",
  "sOowfbi",
  "sOow0",
  "sSow0",
  "sTow0",
  "sOow1",
  "sSow1",
  "sTow1",

  "sDrawTriCMD",
  "sBeginTriCMD",
  "reservedG00",
  "reservedG01",
  "reservedG02",
  "reservedG03",
  "reservedG04",
  "reservedG05",

  "reservedH00",
  "reservedH01",
  "reservedH02",
  "reservedH03",
  "reservedH04",
  "reservedH05",

  "reservedI00",
  "reservedI01",
  "reservedI02",
  "reservedI03",
  "reservedI04",
  "reservedI05",

  "textureMode",
  "tLOD",
  "tDetail",
  "texBaseAddr",
  "texBaseAddr1",
  "texBaseAddr2",
  "texBaseAddr38",
  "trexInit0",
  "trexInit1",
   
  "nccTable000",
  "nccTable001",
  "nccTable002",
  "nccTable003",
  "nccTable004",
  "nccTable005",
  "nccTable006",
  "nccTable007",
  "nccTable008",
  "nccTable009",
  "nccTable00A",
  "nccTable00B",

  "nccTable100",
  "nccTable101",
  "nccTable102",
  "nccTable103",
  "nccTable104",
  "nccTable105",
  "nccTable106",
  "nccTable107",
  "nccTable108",
  "nccTable109",
  "nccTable10A",
  "nccTable10B",

  "tChromaKeyMin",
  "tChromaKeyMax"
};
