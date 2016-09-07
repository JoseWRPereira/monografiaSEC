PDF: PDFLATEX
	evince sec.pdf&

PDFLATEX: LATEX2 
	pdflatex -synctex=1 -interaction=nonstopmode sec


LATEX2: NOMENCLATURA BIB
	pdflatex sec

BIB: LATEX1
	bibtex sec.aux

NOMENCLATURA: LATEX1 sec.nlo
	makeindex sec.nlo -s nomencl.ist -o sec.nls

LATEX1: sec.tex macros.tex
	pdflatex sec	


clear:  *.pdf
	rm *.aux
	rm *.bbl
	rm *.blg
	rm *.ilg
	rm *.lof
	rm *.log
	rm *.lot
	rm *.nlo
	rm *.nls
	rm *.out
	rm *.pdf
	rm *.toc
	rm *.synctex.gz
