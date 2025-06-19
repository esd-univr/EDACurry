
// Generated from g4files/SPECTRELexer.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"


namespace edacurry {


class  SPECTRELexer : public antlr4::Lexer {
public:
  enum {
    BLOCK_COMMENT = 1, LINE_COMMENT = 2, GLOBAL = 3, INCLUDE = 4, CPP_INCLUDE = 5, 
    AHDL_INCLUDE = 6, LIBRARY = 7, LIBRARY_END = 8, SECTION = 9, SECTION_END = 10, 
    SUBCKT = 11, INLINE_SUBCKT = 12, SUBCKT_END = 13, SIMULATOR = 14, GLOBAL_PARAMETERS = 15, 
    MODEL = 16, EXPORT = 17, SAVE = 18, ALTER = 19, ALTERGROUP = 20, OPTIONS = 21, 
    SET = 22, SHELL = 23, INFO = 24, NODESET = 25, IC = 26, ASSERT = 27, 
    CHECK = 28, LANGUAGE = 29, PORTS = 30, WAVE = 31, PWL = 32, SIN = 33, 
    SFFM = 34, PULSE = 35, COEFFS = 36, INSENSITIVE = 37, IF = 38, ELSE = 39, 
    PARAMETERS = 40, ANALOGMODEL = 41, CHECKPOINT = 42, SPECTRE = 43, SPICE = 44, 
    STATISTICS = 45, PROCESS = 46, CORRELATE = 47, TRUNCATE = 48, MISMATCH = 49, 
    VARY = 50, RELIABILITY = 51, AC = 52, ACMATCH = 53, DC = 54, DCMATCH = 55, 
    ENVLP = 56, SP = 57, STB = 58, SWEEP = 59, TDR = 60, TRAN = 61, XF = 62, 
    PAC = 63, PDISTO = 64, PNOISE = 65, PSP = 66, PSS = 67, PXF = 68, PZ = 69, 
    QPAC = 70, QPNOISE = 71, QPSP = 72, QPSS = 73, QPXF = 74, SENS = 75, 
    MONTECARLO = 76, NOISE = 77, CHECKLIMIT = 78, A2D = 79, B3SOIPD = 80, 
    BJT = 81, BJT301 = 82, BJT500 = 83, BJT503 = 84, BJT504 = 85, BJT504T = 86, 
    BSIM1 = 87, BSIM2 = 88, BSIM3 = 89, BSIM3V3 = 90, BSIM4 = 91, BSIMSOI = 92, 
    BTASOI = 93, CAPACITOR = 94, CCCS = 95, CCVS = 96, CKTROM = 97, CORE = 98, 
    D2A = 99, DELAY = 100, DIO500 = 101, DIODE = 102, EKV = 103, FOURIER = 104, 
    GAAS = 105, HBT = 106, HISIM = 107, HVMOS = 108, INDUCTOR = 109, INTCAP = 110, 
    IPROBE = 111, ISOURCE = 112, JFET = 113, JUNCAP = 114, MISNAN = 115, 
    MOS11011 = 116, MOS11010 = 117, MOS3002 = 118, MOS3100 = 119, MOS1000 = 120, 
    MOS1100 = 121, MUTUAL_INDUCTOR = 122, MSLINE = 123, MTLINE = 124, MOS705 = 125, 
    MOS902 = 126, MOS903 = 127, MOS30 = 128, MOS40 = 129, MOS15 = 130, MOS0 = 131, 
    MOS1 = 132, MOS2 = 133, MOS3 = 134, NODCAP = 135, NODE = 136, NPORT = 137, 
    PARAMTEST = 138, PCCCS = 139, PCCVS = 140, PHY_RES = 141, PORT = 142, 
    PSITFT = 143, PVCCS = 144, PVCVS = 145, QUANTITY = 146, RDIFF = 147, 
    RELAY = 148, RESISTOR = 149, SCCCS = 150, SCCVS = 151, SVCCS = 152, 
    SVCVS = 153, SWITCH = 154, TLINE = 155, TOM2 = 156, TOM3 = 157, TRANSFORMER = 158, 
    VBIC = 159, VCCS = 160, VCVS = 161, VSOURCE = 162, WINDING = 163, ZCCCS = 164, 
    ZCCVS = 165, ZVCCS = 166, ZVCVS = 167, BSOURCE = 168, EQUAL = 169, EXCLAMATION_MARK = 170, 
    LESS_THAN = 171, GREATER_THAN = 172, LESS_THAN_EQUAL = 173, GREATER_THAN_EQUAL = 174, 
    LOGIC_EQUAL = 175, LOGIC_NOT_EQUAL = 176, LOGIC_AND = 177, LOGIC_OR = 178, 
    LOGIC_BITWISE_AND = 179, LOGIC_BITWISE_OR = 180, LOGIC_XOR = 181, BITWISE_SHIFT_LEFT = 182, 
    BITWISE_SHIFT_RIGHT = 183, POWER_OPERATOR = 184, AND = 185, OR = 186, 
    COLON = 187, SEMICOLON = 188, PLUS = 189, MINUS = 190, STAR = 191, OPEN_ROUND = 192, 
    CLOSE_ROUND = 193, OPEN_SQUARE = 194, CLOSE_SQUARE = 195, OPEN_CURLY = 196, 
    CLOSE_CURLY = 197, QUESTION_MARK = 198, COMMA = 199, DOLLAR = 200, AMPERSAND = 201, 
    DOT = 202, UNDERSCORE = 203, AT_SIGN = 204, POUND_SIGN = 205, BACKSLASH = 206, 
    SLASH = 207, APEX = 208, QUOTES = 209, PIPE = 210, PERCENT = 211, CARET = 212, 
    TILDE = 213, ARROW = 214, NUMBER = 215, ID = 216, STRING = 217, PERCENTAGE = 218, 
    COMPLEX = 219, WS = 220, NL = 221, CNL = 222
  };

  enum {
    COMMENTS = 2
  };

  SPECTRELexer(antlr4::CharStream *input);
  ~SPECTRELexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace edacurry
