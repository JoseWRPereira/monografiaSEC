PDF: PDFLATEX
	evince sec.pdf&

PDFLATEX: LATEX1
	pdflatex -synctex=1 -interaction=nonstopmode sec


LATEX1: NOMENCLATURA BIB
	pdflatex sec

BIB: LATEX0
	bibtex sec

NOMENCLATURA: LATEX0 sec.nlo
	makeindex sec.nlo -s nomencl.ist -o sec.nls

LATEX0: sec.tex macros.tex
	pdflatex sec	


clear: sec.tex
	rm -f *.aux
	rm -f *.bbl
	rm -f *.bcf
	rm -f *.blg
	rm -f *.ilg
	rm -f *.lof
	rm -f *.log
	rm -f *.lot
	rm -f *.nlo
	rm -f *.nls
	rm -f *.out
	rm -f *.pdf
	rm -f *.run.xm
	rm -f *.toc
	rm -f *.synctex.gz
	rm -f *.run.xml

