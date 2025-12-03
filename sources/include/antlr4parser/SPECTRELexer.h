
// Generated from g4files/SPECTRELexer.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"


namespace edacurry {


class  SPECTRELexer : public antlr4::Lexer {
public:
  enum {
    BLOCK_COMMENT = 1, LINE_COMMENT = 2, GLOBAL = 3, INCLUDE = 4, CPP_INCLUDE = 5, 
    AHDL_INCLUDE = 6, LIBRARY = 7, LIBRARY_END = 8, SECTION = 9, SECTION_END = 10, 
    SUBCKT = 11, INLINE_SUBCKT = 12, SUBCKT_END = 13, SIMULATOR = 14, MODEL = 15, 
    EXPORT = 16, SAVE = 17, ALTER = 18, ALTERGROUP = 19, OPTIONS = 20, SET = 21, 
    SHELL = 22, INFO = 23, NODESET = 24, IC = 25, ASSERT = 26, CHECK = 27, 
    LANGUAGE = 28, PORTS = 29, WAVE = 30, PWL = 31, SIN = 32, SFFM = 33, 
    PULSE = 34, COEFFS = 35, INSENSITIVE = 36, IF = 37, ELSE = 38, PARAMETERS = 39, 
    ANALOGMODEL = 40, CHECKPOINT = 41, SPECTRE = 42, SPICE = 43, STATISTICS = 44, 
    PROCESS = 45, CORRELATE = 46, TRUNCATE = 47, MISMATCH = 48, VARY = 49, 
    RELIABILITY = 50, AC = 51, ACMATCH = 52, DC = 53, DCMATCH = 54, ENVLP = 55, 
    SP = 56, STB = 57, SWEEP = 58, TDR = 59, TRAN = 60, XF = 61, PAC = 62, 
    PDISTO = 63, PNOISE = 64, PSP = 65, PSS = 66, PXF = 67, PZ = 68, QPAC = 69, 
    QPNOISE = 70, QPSP = 71, QPSS = 72, QPXF = 73, SENS = 74, MONTECARLO = 75, 
    NOISE = 76, CHECKLIMIT = 77, A2D = 78, B3SOIPD = 79, BJT = 80, BJT301 = 81, 
    BJT500 = 82, BJT503 = 83, BJT504 = 84, BJT504T = 85, BSIM1 = 86, BSIM2 = 87, 
    BSIM3 = 88, BSIM3V3 = 89, BSIM4 = 90, BSIMSOI = 91, BTASOI = 92, CAPACITOR = 93, 
    CCCS = 94, CCVS = 95, CKTROM = 96, CORE = 97, D2A = 98, DELAY = 99, 
    DIO500 = 100, DIODE = 101, EKV = 102, FOURIER = 103, GAAS = 104, HBT = 105, 
    HISIM = 106, HVMOS = 107, INDUCTOR = 108, INTCAP = 109, IPROBE = 110, 
    ISOURCE = 111, JFET = 112, JUNCAP = 113, MISNAN = 114, MOS11011 = 115, 
    MOS11010 = 116, MOS3002 = 117, MOS3100 = 118, MOS1000 = 119, MOS1100 = 120, 
    MUTUAL_INDUCTOR = 121, MSLINE = 122, MTLINE = 123, MOS705 = 124, MOS902 = 125, 
    MOS903 = 126, MOS30 = 127, MOS40 = 128, MOS15 = 129, MOS0 = 130, MOS1 = 131, 
    MOS2 = 132, MOS3 = 133, NODCAP = 134, NODE = 135, NPORT = 136, PARAMTEST = 137, 
    PCCCS = 138, PCCVS = 139, PHY_RES = 140, PORT = 141, PSITFT = 142, PVCCS = 143, 
    PVCVS = 144, QUANTITY = 145, RDIFF = 146, RELAY = 147, RESISTOR = 148, 
    SCCCS = 149, SCCVS = 150, SVCCS = 151, SVCVS = 152, SWITCH = 153, TLINE = 154, 
    TOM2 = 155, TOM3 = 156, TRANSFORMER = 157, VBIC = 158, VCCS = 159, VCVS = 160, 
    VSOURCE = 161, WINDING = 162, ZCCCS = 163, ZCCVS = 164, ZVCCS = 165, 
    ZVCVS = 166, BSOURCE = 167, EQUAL = 168, EXCLAMATION_MARK = 169, LESS_THAN = 170, 
    GREATER_THAN = 171, LESS_THAN_EQUAL = 172, GREATER_THAN_EQUAL = 173, 
    LOGIC_EQUAL = 174, LOGIC_NOT_EQUAL = 175, LOGIC_AND = 176, LOGIC_OR = 177, 
    LOGIC_BITWISE_AND = 178, LOGIC_BITWISE_OR = 179, LOGIC_XOR = 180, BITWISE_SHIFT_LEFT = 181, 
    BITWISE_SHIFT_RIGHT = 182, POWER_OPERATOR = 183, AND = 184, OR = 185, 
    COLON = 186, SEMICOLON = 187, PLUS = 188, MINUS = 189, STAR = 190, OPEN_ROUND = 191, 
    CLOSE_ROUND = 192, OPEN_SQUARE = 193, CLOSE_SQUARE = 194, OPEN_CURLY = 195, 
    CLOSE_CURLY = 196, QUESTION_MARK = 197, COMMA = 198, DOLLAR = 199, AMPERSAND = 200, 
    DOT = 201, UNDERSCORE = 202, AT_SIGN = 203, POUND_SIGN = 204, BACKSLASH = 205, 
    SLASH = 206, APEX = 207, QUOTES = 208, PIPE = 209, PERCENT = 210, CARET = 211, 
    TILDE = 212, ARROW = 213, NUMBER = 214, ID = 215, STRING = 216, PERCENTAGE = 217, 
    COMPLEX = 218, WS = 219, NL = 220, CNL = 221
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
