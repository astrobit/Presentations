all: Paper 

BASEFILE=PhD_Defense_18_June_2018
TEXFILE=$(BASEFILE).tex
PDFFILE=$(BASEFILE).pdf


$(PDFFILE): $(TEXFILE) *.eps *.tex
	pdflatex $(TEXFILE)
#	bibtex $(BASEFILE)
	pdflatex $(TEXFILE)
	pdflatex $(TEXFILE)
#	dvipdf $(BASEFILE).dvi $(PDFFILE)
#	gs -sOutputFile=$(BASEFILE)_gs.pdf -sDEVICE=pdfwrite -sColorConversionStrategy=Gray -dProcessColorModel=/DeviceGray -dCompatibilityLevel=1.4 -dNOPAUSE -dBATCH $(PDFFILE)

Paper: $(PDFFILE)


clean:
	-rm $(PDFFILE)
	-rm $(BASEFILE).dvi
	-rm $(BASEFILE).log
	-rm $(BASEFILE).aux
	-rm $(BASEFILE).bbl
	-rm $(BASEFILE).blg
	-rm $(BASEFILE).out
	-rm $(BASEFILE).nav
	-rm $(BASEFILE).snm
	-rm $(BASEFILE).toc



